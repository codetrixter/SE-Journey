#!/usr/bin/env python3
"""
Self-Reflection Dashboard Generator
===================================

Walks the curriculum-coverage Markdown files under
``SE-Journey/Analysis-Curriculum-coverage/`` and regenerates a single
``DASHBOARD.md`` (plus an optional ``progress.json``) that summarises how much
of each domain has been studied.

The generator is **dependency-free** (Python standard library only) so it can be
run from a plain Python install or wired into a VS Code task.

Signals parsed from each ``*-covered.md`` file
----------------------------------------------
* GitHub-style checkboxes ``- [x]`` / ``- [ ]``            -> completion counts
* Priority tags ``**Must Know:**`` / ``**Should Know:**``
  / ``**Nice to Have:**``                                  -> weighted scoring
* ``> **Last Analyzed:** <date>``                          -> staleness tracking
* The H1 title ``# <Domain> - Coverage Analysis``          -> display name

Outputs
-------
* ``DASHBOARD.md``            -> single consolidated, cross-domain view
* ``domains/<slug>.md``       -> one focused dashboard per domain, broken down
                                 by the H2 sections inside its coverage file

Usage
-----
    python generate_dashboard.py                 # regenerate every dashboard
    python generate_dashboard.py --json          # also emit progress.json
    python generate_dashboard.py --no-domains    # only the consolidated view
    python generate_dashboard.py --coverage-dir <path> --output <file>
"""

from __future__ import annotations

import argparse
import json
import os
import re
from dataclasses import dataclass, field
from datetime import datetime
from pathlib import Path
from typing import Dict, List, Optional

# --------------------------------------------------------------------------- #
# Configuration
# --------------------------------------------------------------------------- #

SCRIPT_DIR = Path(__file__).resolve().parent
DEFAULT_COVERAGE_DIR = SCRIPT_DIR.parent / "SE-Journey" / "Analysis-Curriculum-coverage"
DEFAULT_OUTPUT = SCRIPT_DIR / "DASHBOARD.md"
DEFAULT_JSON = SCRIPT_DIR / "progress.json"
DEFAULT_DOMAINS_DIR = SCRIPT_DIR / "domains"

# Priority weighting: "Must Know" items count more toward the weighted score.
PRIORITIES = ["Must Know", "Should Know", "Nice to Have", "Untagged"]
WEIGHTS: Dict[str, int] = {
    "Must Know": 3,
    "Should Know": 2,
    "Nice to Have": 1,
    "Untagged": 1,
}

# Staleness thresholds (in days) for the freshness indicator.
STALE_WARN_DAYS = 30
STALE_ALERT_DAYS = 60

# --------------------------------------------------------------------------- #
# Regex patterns
# --------------------------------------------------------------------------- #

CHECKBOX_RE = re.compile(r"^\s*[-*]\s*\[([ xX])\]\s*(.*)$")
PRIORITY_RE = re.compile(r"\*\*(Must Know|Should Know|Nice to Have)\s*:?\*\*")
LAST_ANALYZED_RE = re.compile(r"\*\*Last Analyzed:\*\*\s*(.+?)\s*$")
TITLE_RE = re.compile(r"^#\s+(.*?)\s*$")
SECTION_RE = re.compile(r"^##\s+(.*?)\s*$")
SOURCE_RE = re.compile(r"\*\*Source Folders?:\*\*\s*(.+?)\s*$")

# H2 sections that are prose/summary rather than real curriculum buckets. These
# are ignored when slicing a domain into per-section progress so the per-topic
# dashboard only shows meaningful study areas.
SKIP_SECTION_RE = re.compile(
    r"(coverage summary|progress estimate|key gaps|additional topics)",
    re.IGNORECASE,
)

# Accepted date formats for the "Last Analyzed" line.
DATE_FORMATS = ["%B %d, %Y", "%b %d, %Y", "%Y-%m-%d", "%d %B %Y", "%d %b %Y"]


# --------------------------------------------------------------------------- #
# Data model
# --------------------------------------------------------------------------- #


@dataclass
class SectionStats:
    """Coverage statistics for a single H2 section within a domain file."""

    name: str
    # priority -> {"checked": int, "total": int}
    priority_counts: Dict[str, Dict[str, int]] = field(default_factory=dict)

    def __post_init__(self) -> None:
        if not self.priority_counts:
            self.priority_counts = {
                p: {"checked": 0, "total": 0} for p in PRIORITIES
            }

    @property
    def total(self) -> int:
        return sum(p["total"] for p in self.priority_counts.values())

    @property
    def checked(self) -> int:
        return sum(p["checked"] for p in self.priority_counts.values())

    @property
    def percent(self) -> float:
        return pct(self.checked, self.total)

    @property
    def has_must_know(self) -> bool:
        return self.priority_counts["Must Know"]["total"] > 0

    @property
    def must_percent(self) -> float:
        mk = self.priority_counts["Must Know"]
        return pct(mk["checked"], mk["total"])

    @property
    def focus_metric(self) -> float:
        return self.must_percent if self.has_must_know else self.percent

    @property
    def weighted_percent(self) -> float:
        num = sum(
            WEIGHTS[p] * self.priority_counts[p]["checked"] for p in PRIORITIES
        )
        den = sum(
            WEIGHTS[p] * self.priority_counts[p]["total"] for p in PRIORITIES
        )
        return pct(num, den)

    @property
    def status_label(self) -> str:
        p = self.percent
        if self.total == 0:
            return "— Empty"
        if p >= 100:
            return "✅ Complete"
        if p >= 75:
            return "🟢 Strong"
        if p > 0:
            return "🟡 In Progress"
        return "🔴 Not Started"

    def to_dict(self) -> dict:
        return {
            "name": self.name,
            "total": self.total,
            "checked": self.checked,
            "percent": round(self.percent, 1),
            "must_percent": round(self.must_percent, 1),
            "has_must_know": self.has_must_know,
            "weighted_percent": round(self.weighted_percent, 1),
            "priority_counts": self.priority_counts,
        }


@dataclass
class DomainStats:
    """Aggregated coverage statistics for a single domain file."""

    name: str
    file: Path
    last_analyzed: Optional[datetime] = None
    last_analyzed_raw: str = "Unknown"
    sources: str = ""
    # priority -> {"checked": int, "total": int}
    priority_counts: Dict[str, Dict[str, int]] = field(default_factory=dict)
    # ordered per-H2-section breakdown
    sections: List[SectionStats] = field(default_factory=list)
    # filename (no dir) of the generated per-topic dashboard, e.g. "cpp.md"
    dashboard_filename: str = ""

    def __post_init__(self) -> None:
        if not self.priority_counts:
            self.priority_counts = {
                p: {"checked": 0, "total": 0} for p in PRIORITIES
            }

    # --- raw (unweighted) metrics ------------------------------------------ #

    @property
    def total(self) -> int:
        return sum(p["total"] for p in self.priority_counts.values())

    @property
    def checked(self) -> int:
        return sum(p["checked"] for p in self.priority_counts.values())

    @property
    def percent(self) -> float:
        return pct(self.checked, self.total)

    # --- priority-aware metrics -------------------------------------------- #

    @property
    def has_must_know(self) -> bool:
        return self.priority_counts["Must Know"]["total"] > 0

    @property
    def must_percent(self) -> float:
        mk = self.priority_counts["Must Know"]
        return pct(mk["checked"], mk["total"])

    @property
    def focus_metric(self) -> float:
        """Metric used to rank 'focus next'.

        Domains that tag priorities are ranked by Must-Know coverage. Domains
        with no Must-Know items (e.g. an untagged problem set) fall back to
        overall completion so they are not unfairly flagged as 0%.
        """
        return self.must_percent if self.has_must_know else self.percent

    @property
    def weighted_percent(self) -> float:
        num = sum(
            WEIGHTS[p] * self.priority_counts[p]["checked"] for p in PRIORITIES
        )
        den = sum(
            WEIGHTS[p] * self.priority_counts[p]["total"] for p in PRIORITIES
        )
        return pct(num, den)

    # --- freshness --------------------------------------------------------- #

    @property
    def days_since_analyzed(self) -> Optional[int]:
        if self.last_analyzed is None:
            return None
        return (datetime.now() - self.last_analyzed).days

    @property
    def staleness_flag(self) -> str:
        days = self.days_since_analyzed
        if days is None:
            return "❔ unknown"
        if days >= STALE_ALERT_DAYS:
            return f"🔴 {days}d"
        if days >= STALE_WARN_DAYS:
            return f"🟠 {days}d"
        return f"🟢 {days}d"

    def to_dict(self) -> dict:
        return {
            "name": self.name,
            "file": str(self.file),
            "dashboard": self.dashboard_filename,
            "last_analyzed": self.last_analyzed_raw,
            "days_since_analyzed": self.days_since_analyzed,
            "sources": self.sources,
            "total": self.total,
            "checked": self.checked,
            "percent": round(self.percent, 1),
            "must_percent": round(self.must_percent, 1),
            "has_must_know": self.has_must_know,
            "weighted_percent": round(self.weighted_percent, 1),
            "priority_counts": self.priority_counts,
            "sections": [s.to_dict() for s in self.sections],
        }


# --------------------------------------------------------------------------- #
# Helpers
# --------------------------------------------------------------------------- #


def pct(part: int, whole: int) -> float:
    """Safe percentage that never divides by zero."""
    return (part / whole * 100.0) if whole else 0.0


def render_bar(percent: float, width: int = 10) -> str:
    """Render a text progress bar, e.g. ``██████░░░░``."""
    filled = round(percent / 100.0 * width)
    filled = max(0, min(width, filled))
    return "█" * filled + "░" * (width - filled)


def parse_date(raw: str) -> Optional[datetime]:
    raw = raw.strip()
    for fmt in DATE_FORMATS:
        try:
            return datetime.strptime(raw, fmt)
        except ValueError:
            continue
    return None


def classify_priority(text: str) -> str:
    """Return the priority tag found in a checkbox line, or 'Untagged'."""
    match = PRIORITY_RE.search(text)
    return match.group(1) if match else "Untagged"


def clean_section_name(raw: str) -> str:
    """Strip a leading ``N.`` ordinal and surrounding markup from a heading."""
    name = re.sub(r"^\d+(?:\.\d+)*\.?\s*", "", raw).strip()
    name = name.replace("`", "")
    return name or raw


def slugify(text: str) -> str:
    """Turn a domain name into a filesystem-friendly slug."""
    slug = re.sub(r"[^a-z0-9]+", "-", text.lower()).strip("-")
    return slug or "domain"


def trim_label(text: str, limit: int = 22) -> str:
    """Shorten a long label for chart axes while keeping it readable.

    Double quotes are stripped because the label is embedded inside a
    double-quoted Mermaid string.
    """
    text = text.replace('"', "").strip()
    if len(text) <= limit:
        return text
    return text[: limit - 1].rstrip() + "…"


def md_cell(text: str) -> str:
    """Escape a value so it is safe inside a Markdown table cell."""
    return text.replace("|", "\\|")


# --------------------------------------------------------------------------- #
# Parsing
# --------------------------------------------------------------------------- #


def parse_file(path: Path) -> DomainStats:
    """Parse a single ``*-covered.md`` file into a :class:`DomainStats`."""
    stats = DomainStats(name=path.stem, file=path)
    current_section: Optional[SectionStats] = None

    text = path.read_text(encoding="utf-8", errors="replace")
    for line in text.splitlines():
        # H1 title -> friendly domain name (strip trailing "- Coverage Analysis")
        if stats.name == path.stem:
            title_match = TITLE_RE.match(line)
            if title_match:
                title = title_match.group(1)
                title = re.split(r"\s+[—\-]\s+Coverage", title)[0].strip()
                if title:
                    stats.name = title

        # H2 heading -> start a new per-section bucket (skip prose/summary ones)
        section_match = SECTION_RE.match(line)
        if section_match:
            raw = section_match.group(1).strip()
            if SKIP_SECTION_RE.search(raw):
                current_section = None
            else:
                current_section = SectionStats(name=clean_section_name(raw))
                stats.sections.append(current_section)
            continue

        # Last Analyzed date
        date_match = LAST_ANALYZED_RE.search(line)
        if date_match and stats.last_analyzed is None:
            stats.last_analyzed_raw = date_match.group(1).strip()
            stats.last_analyzed = parse_date(stats.last_analyzed_raw)

        # Source folders
        source_match = SOURCE_RE.search(line)
        if source_match and not stats.sources:
            stats.sources = source_match.group(1).strip().replace("`", "")

        # Checkbox items
        cb_match = CHECKBOX_RE.match(line)
        if cb_match:
            is_checked = cb_match.group(1).lower() == "x"
            priority = classify_priority(cb_match.group(2))
            bucket = stats.priority_counts[priority]
            bucket["total"] += 1
            if is_checked:
                bucket["checked"] += 1
            if current_section is not None:
                sec_bucket = current_section.priority_counts[priority]
                sec_bucket["total"] += 1
                if is_checked:
                    sec_bucket["checked"] += 1

    # Drop sections that contained no checkboxes (e.g. pure prose headings).
    stats.sections = [s for s in stats.sections if s.total > 0]
    stats.dashboard_filename = f"{slugify(stats.name)}.md"
    return stats


def collect_domains(coverage_dir: Path) -> List[DomainStats]:
    """Find and parse every ``*-covered.md`` file under *coverage_dir*."""
    files = sorted(coverage_dir.rglob("*-covered.md"))
    return [parse_file(f) for f in files]


# --------------------------------------------------------------------------- #
# Rendering
# --------------------------------------------------------------------------- #


def aggregate_priority(domains: List[DomainStats]) -> Dict[str, Dict[str, int]]:
    agg = {p: {"checked": 0, "total": 0} for p in PRIORITIES}
    for d in domains:
        for p in PRIORITIES:
            agg[p]["checked"] += d.priority_counts[p]["checked"]
            agg[p]["total"] += d.priority_counts[p]["total"]
    return agg


def build_dashboard(
    domains: List[DomainStats], domains_dirname: Optional[str] = None
) -> str:
    lines: List[str] = []
    now = datetime.now()

    def domain_link(d: DomainStats) -> str:
        """Render the domain name, linked to its per-topic dashboard if any."""
        label = md_cell(d.name)
        if domains_dirname and d.dashboard_filename:
            href = f"{domains_dirname}/{d.dashboard_filename}"
            return f"[{label}]({href})"
        return label

    total_items = sum(d.total for d in domains)
    total_checked = sum(d.checked for d in domains)
    overall_pct = pct(total_checked, total_items)

    weighted_num = sum(
        WEIGHTS[p] * d.priority_counts[p]["checked"]
        for d in domains
        for p in PRIORITIES
    )
    weighted_den = sum(
        WEIGHTS[p] * d.priority_counts[p]["total"]
        for d in domains
        for p in PRIORITIES
    )
    overall_weighted = pct(weighted_num, weighted_den)

    # ---- Header ----------------------------------------------------------- #
    lines += [
        "# 🪞 Self-Reflection Dashboard",
        "",
        "> ⚙️ **Auto-generated** — do not edit by hand. "
        "Run `python Dashboard/generate_dashboard.py` to refresh.",
        f"> 🕒 **Last generated:** {now.strftime('%B %d, %Y %H:%M')}",
        f"> 📚 **Domains tracked:** {len(domains)}",
        "",
    ]
    if domains_dirname:
        lines += [
            "> 🔎 **Per-topic dashboards:** each domain below links to a "
            f"focused breakdown under [`{domains_dirname}/`]({domains_dirname}/).",
            "",
        ]
    lines += [
        "---",
        "",
    ]

    # ---- Headline --------------------------------------------------------- #
    lines += [
        "## 🎯 Overall Progress",
        "",
        f"### `{render_bar(overall_pct, 20)}` **{overall_pct:.1f}%**",
        "",
        f"- ✅ **Completed:** {total_checked} / {total_items} items",
        f"- ⚖️ **Priority-weighted score:** {overall_weighted:.1f}% "
        "*(Must Know ×3, Should Know ×2, Nice to Have ×1)*",
        f"- 🗂️ **Remaining:** {total_items - total_checked} items",
        "",
    ]

    # ---- Overall pie (Mermaid) ------------------------------------------- #
    lines += [
        "```mermaid",
        "pie showData",
        '    title Overall Completion',
        f'    "Completed" : {total_checked}',
        f'    "Remaining" : {total_items - total_checked}',
        "```",
        "",
    ]

    # ---- Per-domain bar chart (Mermaid xychart) -------------------------- #
    sorted_domains = sorted(domains, key=lambda d: d.percent, reverse=True)
    x_labels = ", ".join(f'"{d.name}"' for d in sorted_domains)
    bar_values = ", ".join(f"{d.percent:.0f}" for d in sorted_domains)
    lines += [
        "### 📊 Completion by Domain",
        "",
        "```mermaid",
        "xychart-beta",
        '    title "Completion % by Domain"',
        f"    x-axis [{x_labels}]",
        '    y-axis "Completion %" 0 --> 100',
        f"    bar [{bar_values}]",
        "```",
        "",
        "> ℹ️ *If the bar chart above does not render, your Markdown viewer "
        "needs a recent Mermaid version. The table below always works.*",
        "",
    ]

    # ---- Per-domain table ------------------------------------------------- #
    lines += [
        "## 🧭 Domain Breakdown",
        "",
        "| Domain | Progress | Done | Must-Know | Weighted | Items | Sections | Last Analyzed | Fresh |",
        "|--------|----------|------|-----------|----------|-------|----------|---------------|-------|",
    ]
    for d in sorted_domains:
        must_cell = f"{d.must_percent:.0f}%" if d.has_must_know else "—"
        sections_cell = str(len(d.sections)) if d.sections else "—"
        lines.append(
            f"| **{domain_link(d)}** "
            f"| `{render_bar(d.percent)}` "
            f"| {d.percent:.0f}% "
            f"| {must_cell} "
            f"| {d.weighted_percent:.0f}% "
            f"| {d.checked}/{d.total} "
            f"| {sections_cell} "
            f"| {d.last_analyzed_raw} "
            f"| {d.staleness_flag} |"
        )
    lines.append("")

    # ---- Priority breakdown ---------------------------------------------- #
    agg = aggregate_priority(domains)
    lines += [
        "## 🏷️ Priority Breakdown (all domains)",
        "",
        "| Priority | Progress | Completed | % |",
        "|----------|----------|-----------|---|",
    ]
    for p in PRIORITIES:
        bucket = agg[p]
        if bucket["total"] == 0:
            continue
        p_pct = pct(bucket["checked"], bucket["total"])
        lines.append(
            f"| {priority_label(p)} "
            f"| `{render_bar(p_pct)}` "
            f"| {bucket['checked']}/{bucket['total']} "
            f"| {p_pct:.0f}% |"
        )
    lines.append("")

    # ---- Insights: focus next -------------------------------------------- #
    focus = [d for d in domains if d.percent < 100]
    focus.sort(key=lambda d: (d.focus_metric, d.percent))
    lines += [
        "## 🔴 Focus Next",
        "",
        "*Lowest Must-Know coverage — highest leverage for interview readiness.*",
        "",
    ]
    if focus:
        for d in focus[:3]:
            if d.has_must_know:
                gap = d.priority_counts["Must Know"]
                remaining = gap["total"] - gap["checked"]
                lines.append(
                    f"1. **{domain_link(d)}** — Must-Know at **{d.must_percent:.0f}%** "
                    f"({remaining} must-know item(s) left, "
                    f"{d.percent:.0f}% overall)"
                )
            else:
                remaining = d.total - d.checked
                lines.append(
                    f"1. **{domain_link(d)}** — **{d.percent:.0f}%** overall "
                    f"({remaining} item(s) left)"
                )
    else:
        lines.append("🎉 Everything is complete. Outstanding work!")
    lines.append("")

    # ---- Insights: momentum ---------------------------------------------- #
    momentum = sorted(domains, key=lambda d: d.percent, reverse=True)[:3]
    lines += [
        "## 🏆 Strongest Areas",
        "",
    ]
    for d in momentum:
        lines.append(f"- **{domain_link(d)}** — {d.percent:.0f}% complete 💪")
    lines.append("")

    # ---- Insights: staleness --------------------------------------------- #
    dated = [d for d in domains if d.days_since_analyzed is not None]
    dated.sort(key=lambda d: d.days_since_analyzed or 0, reverse=True)
    lines += [
        "## 📅 Freshness Report",
        "",
        "*Domains not re-analyzed recently may be out of date with your code.*",
        "",
        "| Domain | Last Analyzed | Age | Status |",
        "|--------|---------------|-----|--------|",
    ]
    for d in dated:
        days = d.days_since_analyzed
        status = (
            "🔴 Stale" if days >= STALE_ALERT_DAYS
            else "🟠 Aging" if days >= STALE_WARN_DAYS
            else "🟢 Fresh"
        )
        lines.append(
            f"| {domain_link(d)} | {d.last_analyzed_raw} | {days}d | {status} |"
        )
    if not dated:
        lines.append("| _no dated domains found_ |  |  |  |")
    lines.append("")

    # ---- Footer ----------------------------------------------------------- #
    lines += [
        "---",
        "",
        "<sub>Generated by `Dashboard/generate_dashboard.py` · "
        "data source: `SE-Journey/Analysis-Curriculum-coverage/**/*-covered.md`</sub>",
        "",
    ]

    return "\n".join(lines)


def build_domain_dashboard(
    domain: DomainStats, back_link: str = "../DASHBOARD.md"
) -> str:
    """Render a focused, single-domain dashboard broken down by H2 section."""
    lines: List[str] = []
    now = datetime.now()
    sections = domain.sections

    # ---- Header ----------------------------------------------------------- #
    lines += [
        f"# 🪞 {domain.name} — Topic Dashboard",
        "",
        "> ⚙️ **Auto-generated** — do not edit by hand. "
        "Run `python Dashboard/generate_dashboard.py` to refresh.",
        f"> 🕒 **Last generated:** {now.strftime('%B %d, %Y %H:%M')}",
        f"> 📅 **Last analyzed:** {domain.last_analyzed_raw} ({domain.staleness_flag})",
    ]
    if domain.sources:
        lines.append(f"> 🗂️ **Source folders:** {domain.sources}")
    lines += [
        f"> ↩️ **Back to:** [Consolidated dashboard]({back_link})",
        "",
        "---",
        "",
    ]

    # ---- Headline --------------------------------------------------------- #
    must_line = (
        f"- 🔵 **Must-Know coverage:** {domain.must_percent:.1f}%"
        if domain.has_must_know
        else "- 🔵 **Must-Know coverage:** — *(no Must-Know items tagged)*"
    )
    lines += [
        "## 🎯 Domain Progress",
        "",
        f"### `{render_bar(domain.percent, 20)}` **{domain.percent:.1f}%**",
        "",
        f"- ✅ **Completed:** {domain.checked} / {domain.total} items",
        f"- ⚖️ **Priority-weighted score:** {domain.weighted_percent:.1f}% "
        "*(Must Know ×3, Should Know ×2, Nice to Have ×1)*",
        must_line,
        f"- 🗂️ **Remaining:** {domain.total - domain.checked} items",
        f"- 🧩 **Sections tracked:** {len(sections)}",
        "",
    ]

    # ---- Completion pie --------------------------------------------------- #
    lines += [
        "```mermaid",
        "pie showData",
        f'    title {domain.name} Completion',
        f'    "Completed" : {domain.checked}',
        f'    "Remaining" : {domain.total - domain.checked}',
        "```",
        "",
    ]

    if not sections:
        lines += [
            "> ℹ️ *This domain has no per-section headings to break down, so only "
            "the overall figures above are available.*",
            "",
            "---",
            "",
            "<sub>Generated by `Dashboard/generate_dashboard.py`</sub>",
            "",
        ]
        return "\n".join(lines)

    # ---- Per-section bar chart ------------------------------------------- #
    sorted_sections = sorted(sections, key=lambda s: s.percent, reverse=True)
    x_labels = ", ".join(f'"{trim_label(s.name)}"' for s in sorted_sections)
    bar_values = ", ".join(f"{s.percent:.0f}" for s in sorted_sections)
    lines += [
        "### 📊 Completion by Section",
        "",
        "```mermaid",
        "xychart-beta",
        f'    title "{domain.name}: completion % by section"',
        f"    x-axis [{x_labels}]",
        '    y-axis "Completion %" 0 --> 100',
        f"    bar [{bar_values}]",
        "```",
        "",
        "> ℹ️ *If the chart does not render, the table below always works.*",
        "",
    ]

    # ---- Per-section table ----------------------------------------------- #
    lines += [
        "## 🧭 Section Breakdown",
        "",
        "| Section | Progress | Done | Must-Know | Weighted | Items | Status |",
        "|---------|----------|------|-----------|----------|-------|--------|",
    ]
    for s in sorted_sections:
        must_cell = f"{s.must_percent:.0f}%" if s.has_must_know else "—"
        lines.append(
            f"| **{md_cell(s.name)}** "
            f"| `{render_bar(s.percent)}` "
            f"| {s.percent:.0f}% "
            f"| {must_cell} "
            f"| {s.weighted_percent:.0f}% "
            f"| {s.checked}/{s.total} "
            f"| {s.status_label} |"
        )
    lines.append("")

    # ---- Priority breakdown ---------------------------------------------- #
    agg = {p: {"checked": 0, "total": 0} for p in PRIORITIES}
    for p in PRIORITIES:
        agg[p]["checked"] = domain.priority_counts[p]["checked"]
        agg[p]["total"] = domain.priority_counts[p]["total"]
    lines += [
        "## 🏷️ Priority Breakdown",
        "",
        "| Priority | Progress | Completed | % |",
        "|----------|----------|-----------|---|",
    ]
    for p in PRIORITIES:
        bucket = agg[p]
        if bucket["total"] == 0:
            continue
        p_pct = pct(bucket["checked"], bucket["total"])
        lines.append(
            f"| {priority_label(p)} "
            f"| `{render_bar(p_pct)}` "
            f"| {bucket['checked']}/{bucket['total']} "
            f"| {p_pct:.0f}% |"
        )
    lines.append("")

    # ---- Focus next (within this domain) --------------------------------- #
    focus = [s for s in sections if s.percent < 100]
    focus.sort(key=lambda s: (s.focus_metric, s.percent))
    lines += [
        "## 🔴 Focus Next",
        "",
        "*Lowest-coverage sections — highest leverage inside this domain.*",
        "",
    ]
    if focus:
        for s in focus[:5]:
            remaining = s.total - s.checked
            if s.has_must_know:
                mk = s.priority_counts["Must Know"]
                mk_left = mk["total"] - mk["checked"]
                lines.append(
                    f"1. **{s.name}** — {s.percent:.0f}% overall, "
                    f"Must-Know at {s.must_percent:.0f}% "
                    f"({mk_left} must-know / {remaining} total item(s) left)"
                )
            else:
                lines.append(
                    f"1. **{s.name}** — **{s.percent:.0f}%** "
                    f"({remaining} item(s) left)"
                )
    else:
        lines.append("🎉 Every section in this domain is complete!")
    lines.append("")

    # ---- Strongest sections ---------------------------------------------- #
    strong = [s for s in sorted_sections if s.percent > 0][:5]
    lines += [
        "## 🏆 Strongest Sections",
        "",
    ]
    if strong:
        for s in strong:
            lines.append(f"- **{s.name}** — {s.percent:.0f}% complete 💪")
    else:
        lines.append("_No sections started yet — pick one above to begin._")
    lines.append("")

    # ---- Footer ----------------------------------------------------------- #
    lines += [
        "---",
        "",
        f"<sub>Generated by `Dashboard/generate_dashboard.py` · "
        f"source: `{domain.file.name}`</sub>",
        "",
    ]

    return "\n".join(lines)


def priority_label(priority: str) -> str:
    icons = {
        "Must Know": "🔵 Must Know",
        "Should Know": "🟢 Should Know",
        "Nice to Have": "⚪ Nice to Have",
        "Untagged": "▫️ Untagged",
    }
    return icons.get(priority, priority)


def build_domains_index(domains: List[DomainStats]) -> str:
    """Render an index page linking to every per-topic dashboard."""
    lines: List[str] = []
    now = datetime.now()
    ordered = sorted(domains, key=lambda d: d.percent, reverse=True)
    lines += [
        "# 🗂️ Per-Topic Dashboards",
        "",
        "> ⚙️ **Auto-generated** — do not edit by hand. "
        "Run `python Dashboard/generate_dashboard.py` to refresh.",
        f"> 🕒 **Last generated:** {now.strftime('%B %d, %Y %H:%M')}",
        "",
        "Each domain below has its own focused dashboard with a section-level "
        "breakdown, charts, and \"what to study next\" insights.",
        "",
        "↩️ Back to the [consolidated dashboard](../DASHBOARD.md).",
        "",
        "| Domain | Progress | Done | Must-Know | Sections | Dashboard |",
        "|--------|----------|------|-----------|----------|-----------|",
    ]
    for d in ordered:
        must_cell = f"{d.must_percent:.0f}%" if d.has_must_know else "—"
        sections_cell = str(len(d.sections)) if d.sections else "—"
        lines.append(
            f"| **{md_cell(d.name)}** "
            f"| `{render_bar(d.percent)}` {d.percent:.0f}% "
            f"| {d.checked}/{d.total} "
            f"| {must_cell} "
            f"| {sections_cell} "
            f"| [open ›]({d.dashboard_filename}) |"
        )
    lines += [
        "",
        "---",
        "",
        "<sub>Generated by `Dashboard/generate_dashboard.py`</sub>",
        "",
    ]
    return "\n".join(lines)


def write_domain_dashboards(
    domains: List[DomainStats], domains_dir: Path
) -> List[Path]:
    """Write one dashboard per domain plus an index; return written paths."""
    domains_dir.mkdir(parents=True, exist_ok=True)
    written: List[Path] = []
    for d in domains:
        out = domains_dir / d.dashboard_filename
        out.write_text(build_domain_dashboard(d), encoding="utf-8")
        written.append(out)
    index = domains_dir / "README.md"
    index.write_text(build_domains_index(domains), encoding="utf-8")
    written.append(index)
    return written


# --------------------------------------------------------------------------- #
# Entry point
# --------------------------------------------------------------------------- #


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Generate a self-reflection dashboard from coverage .md files."
    )
    parser.add_argument(
        "--coverage-dir",
        type=Path,
        default=DEFAULT_COVERAGE_DIR,
        help="Directory containing *-covered.md files (recursively).",
    )
    parser.add_argument(
        "--output",
        type=Path,
        default=DEFAULT_OUTPUT,
        help="Path to write the generated DASHBOARD.md.",
    )
    parser.add_argument(
        "--json",
        action="store_true",
        help="Also emit a progress.json snapshot (handy for an HTML view later).",
    )
    parser.add_argument(
        "--domains-dir",
        type=Path,
        default=DEFAULT_DOMAINS_DIR,
        help="Directory to write the per-topic dashboards into.",
    )
    parser.add_argument(
        "--no-domains",
        action="store_true",
        help="Only write the consolidated DASHBOARD.md (skip per-topic pages).",
    )
    args = parser.parse_args()

    coverage_dir: Path = args.coverage_dir
    if not coverage_dir.exists():
        parser.error(f"Coverage directory not found: {coverage_dir}")

    domains = collect_domains(coverage_dir)
    if not domains:
        parser.error(
            f"No '*-covered.md' files found under {coverage_dir}. Nothing to do."
        )

    # Per-topic dashboards (one file per domain) ---------------------------- #
    domains_dirname: Optional[str] = None
    written_domain_files: List[Path] = []
    if not args.no_domains:
        domains_dir: Path = args.domains_dir
        written_domain_files = write_domain_dashboards(domains, domains_dir)
        # Relative link from DASHBOARD.md (in output's folder) to domains dir.
        try:
            domains_dirname = os.path.relpath(
                domains_dir, args.output.resolve().parent
            ).replace(os.sep, "/")
        except ValueError:
            domains_dirname = domains_dir.name

    # Consolidated dashboard ------------------------------------------------ #
    dashboard_md = build_dashboard(domains, domains_dirname=domains_dirname)
    args.output.write_text(dashboard_md, encoding="utf-8")

    total = sum(d.total for d in domains)
    done = sum(d.checked for d in domains)
    print(f"✅ Dashboard written to: {args.output}")
    print(f"   Parsed {len(domains)} domain(s) · {done}/{total} items "
          f"({pct(done, total):.1f}% complete)")
    if written_domain_files:
        print(f"   Per-topic dashboards written to: {args.domains_dir}/ "
              f"({len(written_domain_files)} file(s) incl. index)")

    if args.json:
        snapshot = {
            "generated_at": datetime.now().isoformat(timespec="seconds"),
            "overall": {
                "total": total,
                "checked": done,
                "percent": round(pct(done, total), 1),
            },
            "domains": [d.to_dict() for d in domains],
        }
        DEFAULT_JSON.write_text(
            json.dumps(snapshot, indent=2), encoding="utf-8"
        )
        print(f"   JSON snapshot written to: {DEFAULT_JSON}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())

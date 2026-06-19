# 🪞 Self-Reflection Dashboard

A zero-dependency tool that turns your curriculum-coverage notes into a single,
always-current progress dashboard.

It reads every `*-covered.md` file under
`SE-Journey/Analysis-Curriculum-coverage/` and regenerates:

- [`DASHBOARD.md`](./DASHBOARD.md) — the **consolidated**, cross-domain view, and
- [`domains/`](./domains/) — one **focused dashboard per topic**, each broken
  down by the sections inside that domain's coverage file.

Every page comes with completion percentages, priority-weighted scores,
"what to study next" insights, and Mermaid charts.

---

## 🚀 Quick start

```bash
# From the repo root or this folder:
python3 Dashboard/generate_dashboard.py

# Also write a machine-readable snapshot (progress.json):
python3 Dashboard/generate_dashboard.py --json

# Only regenerate the consolidated DASHBOARD.md (skip per-topic pages):
python3 Dashboard/generate_dashboard.py --no-domains
```

Then open [`DASHBOARD.md`](./DASHBOARD.md) — on GitHub or in VS Code's Markdown
preview (`Ctrl+Shift+V`) the Mermaid charts render automatically. Each domain
row links straight to its [per-topic dashboard](./domains/).

### From VS Code (one click)

A task is pre-wired in `.vscode/tasks.json`:

1. `Ctrl+Shift+P` → **Tasks: Run Task**
2. Choose **Dashboard: Refresh self-reflection dashboard**

---

## 📂 Files

| File | Purpose |
|------|---------|
| `generate_dashboard.py` | The generator (Python 3, standard library only). |
| `DASHBOARD.md`          | **Auto-generated** consolidated view — do not edit by hand. |
| `domains/`              | **Auto-generated** per-topic dashboards + an index `README.md`. |
| `progress.json`         | Optional snapshot (`--json`) for an HTML view / history. |

---

## 🧠 What it measures

Each coverage file is parsed for:

- **Checkboxes** — `- [x]` / `- [ ]` give raw completion counts.
- **Priority tags** — `**Must Know:**`, `**Should Know:**`, `**Nice to Have:**`
  drive a weighted score (×3 / ×2 / ×1). Files without tags are scored on raw
  completion instead.
- **`Last Analyzed` date** — powers the freshness / staleness report.
- **H1 title** — used as the friendly domain name.

The dashboard then surfaces:

- 🎯 Overall + per-domain completion %
- 🧩 **Per-topic dashboards** — each domain sliced into its H2 sections, with
  its own charts, section table, focus list, and strongest areas
- 🔴 **Focus Next** — lowest Must-Know coverage (highest leverage)
- 🏆 **Strongest Areas** — momentum
- 📅 **Freshness Report** — domains that need re-analysis

---

## ⚙️ Options

```text
--coverage-dir <path>   Directory to scan for *-covered.md (default: the
                        SE-Journey/Analysis-Curriculum-coverage folder)
--output <file>         Where to write DASHBOARD.md
--domains-dir <path>    Where to write the per-topic dashboards
                        (default: Dashboard/domains)
--no-domains            Only write the consolidated DASHBOARD.md
--json                  Also write progress.json
```

---

## 🔧 Tuning

Open `generate_dashboard.py` and adjust the constants near the top:

- `WEIGHTS` — change how much each priority counts toward the weighted score.
- `STALE_WARN_DAYS` / `STALE_ALERT_DAYS` — freshness thresholds.

The parser is intentionally forgiving: new coverage files dropped into the
folder are picked up automatically — no configuration needed.

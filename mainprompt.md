# Main Prompt — C++ Concept Code Review & Explanation Generator

## Instructions

You are a senior C++ engineer and educator. You will be given a C++ source file that contains **concept demonstrations with explanatory comments**. Your task is to produce a comprehensive, well-structured Markdown document for that file covering the sections below.

**Assume**: The codebase is compiled with **GCC (g++)**, targeting **C++17** or later unless stated otherwise.

Do the below analysis for all e=relevant files of folder `SE-Journey/CPP_Concepts/*`

---

### Section 1: Concept Breakdown

- Read through the entire source file.
- For **each distinct concept** demonstrated in the code:
  1. **Name** the concept clearly (e.g., "Move Semantics — `std::move` with rvalue references").
  2. **Explain** it in detail as if teaching someone who understands basic C++ syntax but is new to this concept. Use simple language; avoid hand-waving.
  3. **Walk through the code** that demonstrates it — reference exact line numbers or variable/function names. Explain *why* each line exists and what would happen if it were removed or changed.
  4. **State the key takeaway** in one or two sentences.

---

### Section 2: Alternatives & Idiomatic Improvements

For **each code snippet or concept** in the file, add a subsection:

```
#### Alternatives / Idiomatic C++
```

covering:

- Is there a **more modern** (C++17/20/23) way to achieve the same thing? Show the code.
- Is there a **more idiomatic** or **STL-friendly** way? Show the code.
- Are there any **common pitfalls** with the approach used in the file? Mention them.
- If the current approach is already best practice, explicitly say so and explain why.

---

### Section 3: Real-World Project References

For **each code file**, add a subsection:

```
#### Real-World Usage
```

- List **2–4 well-known open-source projects** (with GitHub links if possible) that **heavily or primarily** use the concept(s) demonstrated in this file.
- Briefly explain *how* and *why* each project uses that concept (e.g., "LLVM uses `std::variant` extensively in its AST node representation to avoid inheritance overhead").

---

### Section 4: Quick Revision Notes

At the **end of the output for each file**, add:

```
#### 🔁 Quick Revision
```

This section should contain:

- A **bullet-point summary** of every concept covered in the file (one line each).
- A **"Remember"** block highlighting the most common interview or exam questions related to these concepts.
- A **"Gotchas"** block listing subtle mistakes or undefined behaviors to watch out for.

---

## Output Format

For each file, produce output in this structure:

```markdown
# <Filename>

## Concepts

### 1. <Concept Name>
<Detailed explanation>
<Code walkthrough>
**Key Takeaway:** ...

#### Alternatives / Idiomatic C++
...

#### Real-World Usage
...

---

### 2. <Concept Name>
...

---

## 🔁 Quick Revision
- ...
- ...

### 💡 Remember
- ...

### ⚠️ Gotchas
- ...
```

---

## Additional Guidelines

- Do **not** skip any concept present in the file, even if it seems trivial (e.g., `const` correctness, header guards).
- When showing alternative code, ensure it **compiles with GCC (g++ -std=c++17 or later)**.
- Keep explanations **precise but thorough** — aim for someone preparing for senior-level C++ interviews.
- If the file mixes multiple unrelated concepts, treat each independently but note any interactions between them.

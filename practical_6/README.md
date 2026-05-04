# Practical 6 — String Data Structures & Algorithms

**Course:** CSF303 — Design and Analysis of Algorithms  
**Student:** Pema Tshering Yangchen (2230295)  
**Program:** BE Software Engineering, CST — Royal University of Bhutan

---

## Problems

| # | Problem | Algorithm | Key Concept |
|---|---------|-----------|-------------|
| 1 | [Basic Trie](./P1_Trie/README.md) | Trie (Prefix Tree) | Insert, Search, Delete on a character-level tree |
| 2 | [PATRICIA Trie](./P2_PATRICIA/README.md) | PATRICIA Trie | Bit-indexed branching with back-edges; one node per key |
| 3 | [Manacher's Algorithm](./P3_Manacher/README.md) | Manacher's | O(n) longest palindromic substring via mirror optimisation |

---

## Quick Start

```bash
# P1 — Trie
cd P1_Trie && g++ -o p1 trie.cpp && ./p1

# P2 — PATRICIA
cd P2_PATRICIA && g++ -o p2 patricia.cpp && ./p2

# P3 — Manacher
cd P3_Manacher && g++ -o p3 manacher.cpp && ./p3
```

---

## Concepts at a Glance

```
Trie        — one node per character; O(m) ops; great for prefix search
PATRICIA    — one node per key; branches on bit index; memory-efficient
Manacher's  — O(n) palindrome detection using palindrome mirror property
```
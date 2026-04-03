# Part 1 — Borůvka's Algorithm (Trace and Analysis)

Graph (vertices A–G mapped to 0–6):
- Edges (u-v : w):
  - 0-1:4, 0-2:3, 1-2:1, 1-3:5,
  - 2-3:6, 2-4:2, 3-4:8, 3-5:7,
  - 4-5:9, 4-6:3, 5-6:4

Round 1 (initial components: single vertices)
- Component 0 (A): cheapest outgoing = 0-2 (w=3)
- Component 1 (B): cheapest outgoing = 1-2 (w=1)
- Component 2 (C): cheapest outgoing = 1-2 (same edge, w=1)
- Component 3 (D): cheapest outgoing = 1-3 (w=5)
- Component 4 (E): cheapest outgoing = 2-4 (w=2)
- Component 5 (F): cheapest outgoing = 5-6 (w=4)
- Component 6 (G): cheapest outgoing = 6-4 (w=3)

Selected unique edges (after deduplication):
- 0-2 (3), 1-2 (1), 1-3 (5), 2-4 (2), 5-6 (4), 6-4 (3)

Merges after Round 1 (applying unions): these edges connect all vertices into a single component.

Result after Round 1: single component containing all vertices -> algorithm terminates.

Final MST edges (using 0-based indices, map back to letters):
- 1-2 (B–C) : 1
- 2-4 (C–E) : 2
- 0-2 (A–C) : 3
- 4-6 (E–G) : 3
- 5-6 (F–G) : 4
- 1-3 (B–D) : 5

Mapping to letters:
- B–C (1), C–E (2), A–C (3), E–G (3), F–G (4), B–D (5)

Total MST weight = 1 + 2 + 3 + 3 + 4 + 5 = 18

**Output:**
![alt text](image.png)

Implementation
- See `P1_Boruvka/boruvka.cpp` for the C++ implementation using Union-Find with path compression and union by rank.

Complexity and rounds bound
- Each round selects at most one outgoing edge per component and performs unions; the number of components at least halves every round in the worst case, hence rounds ≤ O(log V).
- Each round scans edges to find cheapest outgoing edges: O(E) work per round. With O(log V) rounds the total time is O(E log V) for the selection phase. Using union-find with near-constant amortized union/find gives overall expected time O(E log V).

Notes
- In this particular graph the algorithm completed in one round because the set of cheapest outgoing edges immediately connected all vertices.

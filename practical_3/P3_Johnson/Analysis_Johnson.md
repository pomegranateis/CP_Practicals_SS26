# Part 3 — Johnson's Algorithm (Trace and Analysis)

Using the same directed graph as in Part 2.

Steps performed in implementation:
- Add source s connected to every vertex with 0-weight edges and run Bellman-Ford to obtain h[v]. (Implementation originally included this; if omitted you can set h via manual reasoning.)
- Reweight edges w'(u,v) = w(u,v) + h(u) - h(v). These are guaranteed non-negative if no negative cycles.
- Run Dijkstra from each vertex on reweighted graph; then recover true distances d(u,v) = d'(u,v) - h(u) + h(v).

Results (from program): the recovered distance matrix matches Floyd–Warshall's final matrix in Part 2.

**Output:**
![alt text](image.png)

Implementation
- See `P3_Johnson/johnson.cpp` for the C++ implementation using Bellman-Ford for reweighting and binary heap Dijkstra for per-source runs.

Complexity
- Bellman-Ford: O(VE)
- Dijkstra from each vertex: O(V * (E log V)) → total O(VE log V) for naive implementation; with Fibonacci heaps this reduces but binary heap is typical in contests.
- Overall: O(VE + V * E log V) simplified to O(VE log V) with binary heaps; often described as O(VE + V^2 log V) depending on representation.

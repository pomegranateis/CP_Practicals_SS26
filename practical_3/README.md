# Practical 3 - MST & All-Pairs Shortest Path Algorithms

Pema Tshering Yangchen — 2230295

This practical implements and analyzes:
- Borůvka's algorithm (MST)
- Floyd–Warshall (All-pairs shortest paths)
- Johnson's algorithm (All-pairs with negative weights)

## Table of Contents

1. [P1 — Borůvka's Algorithm](#p1--borůvkas-algorithm)
2. [P2 — Floyd–Warshall](#p2--floydwarshall)
3. [P3 — Johnson's Algorithm](#p3--johnsons-algorithm)

---

## P1 — Borůvka's Algorithm

**Minimum Spanning Tree (MST)**

Brief: Construct MST using Borůvka's algorithm with Union-Find. Trace algorithm round-by-round to identify cheapest outgoing edges per component and merges.

Files: [`P1_Boruvka/boruvka.cpp`](P1_Boruvka/boruvka.cpp) | [`P1_Boruvka/Analysis_Boruvka.md`](P1_Boruvka/Analysis_Boruvka.md)

How to run:
```bash
cd P1_Boruvka
g++ -O2 -std=gnu++17 -o boruvka boruvka.cpp
./boruvka
```

---

## P2 — Floyd–Warshall

**All-Pairs Shortest Paths**

Brief: Compute shortest paths between all vertex pairs using dynamic programming. Show matrices D^0 through D^5 (intermediate vertices k = 0..4) and detect negative cycles.

Files: [`P2_FloydWarshall/floyd.cpp`](P2_FloydWarshall/floyd.cpp) | [`P2_FloydWarshall/Analysis_Floyd.md`](P2_FloydWarshall/Analysis_Floyd.md)

How to run:
```bash
cd P2_FloydWarshall
g++ -O2 -std=gnu++17 -o floyd floyd.cpp
./floyd
```

---

## P3 — Johnson's Algorithm

**All-Pairs Shortest Paths with Negative Weights**

Brief: Run Bellman-Ford for reweighting, then Dijkstra from each vertex on reweighted graph. Recover true distances and verify match with Floyd–Warshall.

Files: [`P3_Johnson/johnson.cpp`](P3_Johnson/johnson.cpp) | [`P3_Johnson/Analysis_Johnson.md`](P3_Johnson/Analysis_Johnson.md)

How to run:
```bash
cd P3_Johnson
g++ -O2 -std=gnu++17 -o johnson johnson.cpp
./johnson
```

---

## Complexity Summary

| Algorithm | Time | Space | Denseness |
|---|---:|---:|---|
| Borůvka | O(E log V) | O(V+E) | Sparse or dense |
| Floyd–Warshall | O(V³) | O(V²) | Dense |
| Johnson | O(VE + V² log V) | O(V+E) | Sparse |

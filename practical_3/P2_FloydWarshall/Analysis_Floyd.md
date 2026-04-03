# Part 2 — Floyd–Warshall (Trace and Analysis)

Graph (nodes 1..5 mapped to 0..4) edges:
- 0→1:3, 0→2:8, 1→3:1, 1→4:7, 2→1:4, 3→0:2, 3→2:-5, 4→3:6

Initial distance matrix D^0 (INF denotes no direct edge):
```
[  0   3   8  INF  INF ]
[INF   0  INF   1    7 ]
[INF   4   0  INF  INF ]
[  2  INF  -5   0  INF ]
[INF INF INF   6    0 ]
```

Run Floyd–Warshall updating with k from 1..5 (0..4 indexing)

D^1 (k=0): consider paths via vertex 0
```
[  0   3   8  INF  INF ]
[INF   0  INF   1    7 ]
[INF   4   0  INF  INF ]
[  2   5   10  INF  INF ]
[INF INF INF   6    0 ]
```

D^2 (k=1): consider paths via vertex 1
```
[  0   3   8   4   10 ]
[INF   0  INF   1    7 ]
[INF   4   0   5   11 ]
[  2   5   10  INF  INF ]
[INF INF INF   6    0 ]
```

D^3 (k=2): consider paths via vertex 2
```
[  0   3   8   4   10 ]
[INF   0  INF   1    7 ]
[INF   4   0   5   11 ]
[  2   5   10  INF  INF ]
[INF INF INF   6    0 ]
```
(Note: no changes in this step)

D^4 (k=3): consider paths via vertex 3
```
[  0   3   8   4   10 ]
[  3   0  -1   1    7 ]
[  7  10   0   6   12 ]
[  2   5   10  INF  INF ]
[  8  11   6   6    0 ]
```

D^5 (k=4): consider paths via vertex 4
```
[  0   3   8   4   10 ]
[  3   0  -1   1    7 ]
[  7  10   0   6   12 ]
[  2   5   10  -3    9 ]
[  8  11   6   6    0 ]
```

**Output:**
![alt text](image.png)

Final matrix D^5 above. Note: diagonal entries d[i][i] are all >= 0, so no negative cycle detected.

Implementation
- See `P2_FloydWarshall/floyd.cpp` for the C++ implementation that outputs the final matrix and negative-cycle flag.

Complexity
- Time: O(V^3)
- Space: O(V^2)

# Practical 2

Pema Tshering Yangchen — 2230295
Module: Competitive Programming Practicals

This folder contains solutions and analysis for six problems focusing on bitmask DP, greedy bitwise selection, deques, segment trees, Dijkstra variants, and DP over states.

## Table of Contents

- [P1 — Dinner Table Arrangements](#p1-—-dinner-table-arrangements)
- [P2 — Maximum AND Subarray](#p2-—-maximum-and-subarray)
- [P3 — Sliding Window Maximum](#p3-—-sliding-window-maximum)
- [P4 — Sliding Window with Updates (Segment Tree)](#p4-—-sliding-window-with-updates-segment-tree)
- [P5 — Network Latency (P5a & P5b)](#p5-—-network-latency-p5a--p5b)
- [P6 — Toll Booths (Skips DP)](#p6-—-toll-booths-skips-dp)

---

## P1 — Dinner Table Arrangements

Brief: Arrange N people around a circular table so adjacent people share no allergy. The solution uses bitmask dynamic programming to test feasible orderings and verifies the circular closure.

Files: [P1/P1.cpp](P1/P1.cpp) | [P1/Analysis1.md](P1/Analysis1.md)

How to run:
```bash
cd P1
g++ -O2 -std=gnu++17 -o p1 P1.cpp
# then run with your input file
./p1 < input.txt
```

---

## P2 — Maximum AND Subarray

Brief: Find the maximum integer X such that some contiguous subarray of length at least K has all elements containing X's bits. The implementation greedily selects bits from MSB to LSB and verifies with a linear scan.

Files: [P2/P2.cpp](P2/P2.cpp) | [P2/Analysis2.md](P2/Analysis2.md)

How to run:
```bash
cd P2
g++ -O2 -std=gnu++17 -o p2 P2.cpp
./p2 < input.txt
```

---

## P3 — Sliding Window Maximum

Brief: Compute the maximum for every sliding window of size K over an array of length N. Uses a monotonic deque to maintain candidates and produce each window maximum in amortized O(1).

Files: [P3/P3.cpp](P3/P3.cpp) | [P3/Analysis3.md](P3/Analysis3.md)

How to run:
```bash
cd P3
g++ -O2 -std=gnu++17 -o p3 P3.cpp
./p3 < input.txt
```

---

## P4 — Sliding Window with Updates (Segment Tree)

Brief: Support point updates and queries asking for the maximum of the window ending at index i. Solved with a segment tree for range maximum and point updates.

Files: [P4/P4.cpp](P4/P4.cpp) | [P4/Analysis4.md](P4/Analysis4.md)

How to run:
```bash
cd P4
g++ -O2 -std=gnu++17 -o p4 P4.cpp
./p4 < input.txt
```

---

## P5 — Network Latency (P5a & P5b)

Brief: P5a computes shortest paths in a static weighted graph using Dijkstra. P5b extends to time-dependent edge costs of the form a·t + b and runs a modified Dijkstra over continuous arrival times.

Files: [P5/P5a.cpp](P5/P5a.cpp) | [P5/P5b.cpp](P5/P5b.cpp) | [P5/Analysis5.md](P5/Analysis5.md)

How to run P5a:
```bash
cd P5
g++ -O2 -std=gnu++17 -o p5a P5a.cpp
./p5a < input.txt
```

How to run P5b:
```bash
cd P5
g++ -O2 -std=gnu++17 -o p5b P5b.cpp
./p5b < input.txt
```

---

## P6 — Toll Booths (Skips DP)

Brief: Travel from booth 1 to N minimizing time; each booth has a toll and you can skip paying up to K times. The solution uses a DP over position × skips storing (time, coins) and relaxes transitions for paying or skipping.

Files: [P6/P6.cpp](P6/P6.cpp) | [P6/Analysis6.md](P6/Analysis6.md)

How to run:
```bash
cd P6
g++ -O2 -std=gnu++17 -o p6 P6.cpp
./p6 < input.txt
```

---

## Notes

- Each problem folder contains a run screenshot (PNG) and an `Analysis*.md` file with a detailed walkthrough, complexity bounds and the captured output. Use those analysis files for in-depth explanations.
- Compile flags used: `-std=gnu++17 -O2`.

---

## Summary Table

| Problem | Technique | Time Complexity | Space Complexity |
|---|---|---:|---:|
| P1 | Bitmask DP | O(2^N · N^2) | O(2^N · N) |
| P2 | Greedy bit-by-bit + scans | O(B · N) | O(N) |
| P3 | Monotonic deque | O(N) | O(K) |
| P4 | Segment tree (range max) | O((N+Q) log N) | O(N) |
| P5a | Dijkstra (static) | O((N+M) log N) | O(N+M) |
| P5b | Modified Dijkstra (time-dependent) | O((N+M) log N) | O(N+M) |
| P6 | DP over skips (2D) | O(N · K) | O(N · K) |

---

If you want, I can now:
- Insert the exact command lines and captured outputs from each folder's screenshots into this README for quick reference, or
- Create a `run_all.sh` script that compiles and runs all problems and places captured outputs into their folders.

Which should I do next?

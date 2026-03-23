# CP Practicals 1 - Programming Problems

This folder contains solutions to 10 competitive programming problems focusing on **vectors/dynamic arrays**, **deques**, **priority queues**, and **bitmask techniques**.

## Table of Contents

1. [Dynamic Array Basics](#problem-1-dynamic-array-basics)
2. [Reverse the Array](#problem-2-reverse-the-array)
3. [Remove Duplicates](#problem-3-remove-duplicates)
4. [Sliding Window Maximum](#problem-4-sliding-window-maximum)
5. [Balanced Line Problem](#problem-5-balanced-line-problem)
6. [K Largest Elements](#problem-6-k-largest-elements)
7. [Running Median](#problem-7-running-median)
8. [Subset Generation](#problem-8-subset-generation)
9. [Count Subsets with Even Sum](#problem-9-count-subsets-with-even-sum)
10. [Count Subsets with Target Sum](#problem-10-count-subsets-with-target-sum)

---

## Problem 1: Dynamic Array Basics

**Problem Summary:**  
Read N integers, store them in a dynamic container, and print the maximum element, minimum element, and sum of all elements.

**Data Structure:** Vector  
**Screenshot:**

```terminal
$ g++ -O2 -std=gnu++17 -o Problem1 Problem1.cpp
$ printf "5\n1 2 3 4 5\n" | ./Problem1
Enter N: Enter 5 integers:
Maximum: 5
Minimum: 1
Sum:     15
```

**Files:** [`problem1/Problem1.cpp`](problem1/Problem1.cpp) | [`problem1/Analysis1.md`](problem1/Analysis1.md)

---

## Problem 2: Reverse the Array

**Problem Summary:**  
Given N integers, print the array in reverse order.

**Data Structure:** Vector  
**Screenshot:**

```terminal
$ g++ -O2 -std=gnu++17 -o Problem2 Problem2.cpp
$ printf "5\n1 2 3 4 5\n" | ./Problem2
Enter N: Enter 5 integers: Reversed: 5 4 3 2 1
```

**Files:** [`problem2/Problem2.cpp`](problem2/Problem2.cpp) | [`problem2/Analysis2.md`](problem2/Analysis2.md)

---

## Problem 3: Remove Duplicates

**Problem Summary:**  
Given N integers, remove duplicates and print only unique values in sorted order.

**Data Structure:** Vector  
**Screenshot:**

```terminal
$ g++ -O2 -std=gnu++17 -o Problem3 Problem3.cpp
$ printf "6\n3 1 4 1 5 9\n" | ./Problem3
Enter N: Enter 6 integers: Unique elements: 1 3 4 5 9
```

**Files:** [`problem3/Problem3.cpp`](problem3/Problem3.cpp) | [`problem3/Analysis3.md`](problem3/Analysis3.md)

---

## Problem 4: Sliding Window Maximum

**Problem Summary:**  
Given an array of size N and window size K, print the maximum element in every sliding window of size K.

**Data Structure:** Deque  
**Screenshot:**

```terminal
$ g++ -O2 -std=gnu++17 -o Problem4 Problem4.cpp
$ printf "8 3\n1 3 -1 -3 5 3 6 7\n" | ./Problem4
Enter N and K: Enter 8 integers: Sliding window maximums: 3 3 5 5 6 7
```

**Files:** [`problem4/Problem4.cpp`](problem4/Problem4.cpp) | [`problem4/Analysis4.md`](problem4/Analysis4.md)

---

## Problem 5: Balanced Line Problem

**Problem Summary:**  
Simulate a line where people can enter from the front or back, and leave from the front or back. Support four operations: `push_front`, `push_back`, `pop_front`, `pop_back`. Print the contents after each operation.

**Data Structure:** Deque  
**Screenshot:**

```terminal
$ g++ -O2 -std=gnu++17 -o Problem5 Problem5.cpp
$ printf "6\npush_back 3\npush_front 2\npush_back 5\npop_front\npop_back\npop_front\n" | ./Problem5
Enter number of operations: Operation: Line: [3]
Operation: Line: [2, 3]
Operation: Line: [2, 3, 5]
Operation: Line: [3, 5]
Operation: Line: [3]
Operation: Line: []
```

**Files:** [`problem5/Problem5.cpp`](problem5/Problem5.cpp) | [`problem5/Analysis5.md`](problem5/Analysis5.md)

---

## Problem 6: K Largest Elements

**Problem Summary:**  
Given N numbers, print the K largest numbers in descending order.

**Data Structure:** Priority Queue (Max Heap)  
**Screenshot:**

```terminal
$ g++ -O2 -std=gnu++17 -o Problem6 Problem6.cpp
$ printf "6 3\n7 1 5 3 9 2\n" | ./Problem6
Enter N and K: Enter 6 integers: Top 3 largest elements: 9 7 5
```

**Files:** [`problem6/Problem6.cpp`](problem6/Problem6.cpp) | [`problem6/Analysis6.md`](problem6/Analysis6.md)

---

## Problem 7: Running Median

**Problem Summary:**  
Find the running median of a stream of numbers. After reading each number, output the median of all numbers read so far.

**Data Structure:** Priority Queue (Min Heap & Max Heap)  
**Screenshot:**

```terminal
$ g++ -O2 -std=gnu++17 -o Problem7 Problem7.cpp
$ printf "6\n12 4 5 3 8 7\n" | ./Problem7
12.0
8.0
5.0
4.5
5.0
6.0
```

**Files:** [`problem7/Problem7.cpp`](problem7/Problem7.cpp) | [`problem7/Analysis7.md`](problem7/Analysis7.md)

---

## Problem 8: Subset Generation

**Problem Summary:**  
Given a set of N numbers, print all possible subsets (the power set).

**Data Structure:** Bitmask  
**Screenshot:**

```terminal
$ g++ -O2 -std=gnu++17 -o Problem8 Problem8.cpp
$ printf "3\n1 2 3\n" | ./Problem8
Enter N: Enter 3 integers: All subsets:
{ }
{ 1 }
{ 2 }
{ 1 2 }
{ 3 }
{ 1 3 }
{ 2 3 }
{ 1 2 3 }
```

**Files:** [`problem8/Problem8.cpp`](problem8/Problem8.cpp) | [`problem8/Analysis8.md`](problem8/Analysis8.md)

---

## Problem 9: Count Subsets with Even Sum

**Problem Summary:**  
Given N numbers, count how many subsets have an even sum.

**Data Structure:** Bitmask  
**Screenshot:**

```terminal
$ g++ -O2 -std=gnu++17 -o Problem9 Problem9.cpp
$ printf "4\n1 2 3 4\n" | ./Problem9
Enter N: Enter 4 integers: Number of subsets with even sum: 8
```

**Files:** [`problem9/Problem9.cpp`](problem9/Problem9.cpp) | [`problem9/Analysis9.md`](problem9/Analysis9.md)

---

## Problem 10: Count Subsets with Target Sum

**Problem Summary:**  
Given N numbers and a target sum X, count how many subsets have a sum equal to X.

**Data Structure:** Bitmask  
**Screenshot:**

```terminal
$ g++ -O2 -std=gnu++17 -o Problem10 Problem10.cpp
$ printf "4\n1 2 3 4\n5\n" | ./Problem10
Enter N: Enter 4 integers: Enter target sum: Number of subsets with sum 5: 2
```

**Files:** [`problem10/Problem10.cpp`](problem10/Problem10.cpp) | [`problem10/Analysis10.md`](problem10/Analysis10.md)

---

## .gitignore

Add the following to the repo root `.gitignore`:

```
# Compiled binaries and machine-generated artifacts
*.o
*.out
*.exe
Problem*
*.txt

# OS artifacts
.DS_Store
Thumbs.db
```

These files are machine-generated artifacts (binaries and outputs). They should not be committed because they are large, unreproducible across platforms, and clutter the git history.

---

## Notes

- All programs compiled with `-std=gnu++17` and `-O2`.
- Interactive prompts are captured in the terminal screenshots/blocks above.

---

Please save this as `README.md` inside the `practical_1` folder. Also create/update the `.gitignore` at the repo root as specified.

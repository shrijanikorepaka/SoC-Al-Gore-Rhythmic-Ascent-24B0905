# Week 2 (2 June - 8 June): 

## Goals for the week
- Learn some more data structures (linked list, hash maps, trees)
- Learn and implement sorting algorithms
- Analyze time and space complexity of sorting techniques

---
## 🛠️ Task Breakdown

### 1. More Data Structures

#### Linked List
- [Linked Lists CS50 Harvard University](https://www.youtube.com/watch?v=2T-A_GFuoTo&t=650s)
- [Linked Lists vs. Arrays](https://www.coursera.org/lecture/data-structures-optimizing-performance/core-linked-lists-vs-arrays-rjBs9)
- **Implementation Practice:**
  - Singly Linked List (insert, delete, search)
  - Doubly Linked List
  - Circular Linked List
- **Key Concepts:** Node structure, pointers, memory allocation

#### Hash Maps/Hash Tables
- **Learning Resources:**
  - Hash table fundamentals and collision handling
  - Load factor and rehashing concepts
- **Implementation Practice:**
  - Basic hash table with chaining
  - Hash functions (division method, multiplication method)
  - Collision resolution (separate chaining, open addressing)
- **Key Concepts:** Hash functions, collisions, time complexity O(1) average case

#### Trees
- **Binary Trees:**
  - Tree traversal (inorder, preorder, postorder)
  - Binary Search Trees (BST)
  - Tree insertion, deletion, and search operations
- **Learning Resources:**
  - Tree terminology (root, leaf, height, depth)
  - Balanced vs unbalanced trees
- **Key Concepts:** Recursive algorithms, tree properties, BST invariant

---

### 2. Sorting Algorithms

#### Elementary Sorting Algorithms
- **Bubble Sort**
  - Time: O(n²), Space: O(1)
  - Implementation and optimization (early termination)
- **Selection Sort**
  - Time: O(n²), Space: O(1)
  - Find minimum element approach
- **Insertion Sort**
  - Time: O(n²) worst case, O(n) best case, Space: O(1)
  - Efficient for small datasets and nearly sorted arrays

#### Advanced Sorting Algorithms
- **Merge Sort**
  - Time: O(n log n), Space: O(n)
  - Divide and conquer approach
  - Stable sorting algorithm
- **Quick Sort**
  - Time: O(n log n) average, O(n²) worst case, Space: O(log n)
  - Partitioning and pivot selection strategies
- **Heap Sort**
  - Time: O(n log n), Space: O(1)
  - Binary heap data structure

#### Specialized Sorting
- **Counting Sort** (for integers in limited range)
  - Time: O(n + k), Space: O(k)
- **Radix Sort** (for integers)
  - Time: O(d × (n + k)), Space: O(n + k)

#### Complexity Analysis Practice
- Best, average, and worst-case scenarios
- Space complexity considerations
- Stability and adaptability of algorithms
- When to use which sorting algorithm

---

### 3. Problems

#### Linked List Problems
1. **Reverse a Linked List** (LeetCode 206)
2. **Merge Two Sorted Lists** (LeetCode 21)
3. **Detect Cycle in Linked List** (LeetCode 141)
4. **Remove Nth Node From End** (LeetCode 19)
5. **Find Middle of Linked List** (LeetCode 876)

#### Hash Map Problems
1. **Two Sum** (LeetCode 1)
2. **Group Anagrams** (LeetCode 49)
3. **First Unique Character** (LeetCode 387)
4. **Valid Anagram** (LeetCode 242)
5. **Hash Map Implementation** (Design your own)

#### Tree Problems
1. **Binary Tree Inorder Traversal** (LeetCode 94)
2. **Maximum Depth of Binary Tree** (LeetCode 104)
3. **Validate Binary Search Tree** (LeetCode 98)
4. **Binary Tree Level Order Traversal** (LeetCode 102)
5. **Lowest Common Ancestor of BST** (LeetCode 235)

#### Sorting Problems
1. **Sort an Array** (LeetCode 912) - Implement multiple algorithms
2. **Merge Intervals** (LeetCode 56)
3. **Largest Number** (LeetCode 179)
4. **Sort Colors** (LeetCode 75) - Dutch National Flag
5. **Kth Largest Element** (LeetCode 215)

---

### Questions to be submitted:

#### Theory Questions
1. Compare and contrast arrays vs linked lists in terms of memory usage, access time, and insertion/deletion operations.
2. Explain the trade-offs between different collision resolution techniques in hash tables.
3. When would you choose Quick Sort over Merge Sort, and vice versa?
4. What makes a sorting algorithm "stable" and why does it matter?

#### Implementation Questions
1. Implement a singly linked list with insert, delete, and search operations.
2. Design a hash table that handles collisions using separate chaining.
3. Implement merge sort and analyze its time complexity step by step.
4. Write a function to validate if a binary tree is a valid BST.

#### Problem-Solving Questions
1. Given an array of integers, find two numbers that add up to a target sum using a hash map.
2. Reverse a linked list both iteratively and recursively.
3. Sort an array using at least three different algorithms and compare their performance.
4. Find the kth largest element in an unsorted array without fully sorting it.

---

## 📚 Additional Resources
- **Books:** "Introduction to Algorithms" (CLRS) - Chapters on sorting and data structures
- **Online Platforms:** LeetCode, HackerRank, GeeksforGeeks
- **Visualization Tools:** VisuAlgo.net for algorithm animations
- **Practice:** Implement each data structure and algorithm from scratch before using built-in libraries

## ⏰ Time Allocation Suggestion
- **Day 1-2:** Linked Lists (theory + implementation + problems)
- **Day 3:** Hash Maps (theory + implementation + problems)
- **Day 4:** Trees (theory + basic operations + problems)
- **Day 5-6:** Sorting Algorithms (implementation + complexity analysis)
- **Day 7:** Problem solving and review

## Goals for the week

- Learn some more data structures (linked list, hash maps, trees)
- learn and implement sorting algorithms
- Analyze time and space complexity of sorting techniques.

---

## 🛠️ Task Breakdown

### 1. More Data Structures

- Linked List
  - [Linked Lists CS50 Harvard University](https://www.youtube.com/watch?v=2T-A_GFuoTo&t=650s)
  - [Linked Lists vs. Arrays](https://www.coursera.org/lecture/data-structures-optimizing-performance/core-linked-lists-vs-arrays-rjBs9)



### 2. Sorting algorithms


---

### 3. Problems

- ### Questions to be submitted:



---

### 4. Tasks for Competitive Programming

- Go through [C++ sort](https://www.geeksforgeeks.org/sort-c-stl/) function.
- Read Chapter 5 and Chapter 8 from this [Competitive Programmer's Handbook](https://github.com/sakshamrathi21/SOC-Conquering_Competitive_Programming/blob/main/Resources/Competitive%20Programmer_s%20Handbook.pdf?usp=sharing).
- Go through Chapters 4-5 and 8 from this [Guide to Competitive Programming](https://github.com/sakshamrathi21/SOC-Conquering_Competitive_Programming/blob/main/Resources/Guide%20to%20Competitive%20Programming.pdf?usp=sharing).
- Please read this [document](https://github.com/sakshamrathi21/SOC-Conquering_Competitive_Programming/blob/main/Resources/Some%20Techniques.pdf) for some common techniques.
- ### Questions to be submitted:
    1. [Playlist](https://cses.fi/problemset/task/1141) (w2\_q1.cpp)
    1. [Sum of Two Values](https://cses.fi/problemset/task/1640) (w2\_q2.cpp)
    1. [Sum of Three Values](https://cses.fi/problemset/task/1641) (w2\_q3.cpp)
    1. [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/description/)(w2\_q4.cpp)
    1. [Stick Lengths](https://cses.fi/problemset/task/1074) (w2\_q5.cpp)
- ### Questions for your practice 
    1. [Min Max Sort](https://codeforces.com/problemset/problem/1792/C)
    1. [2^Sort](https://codeforces.com/problemset/problem/1692/G)				
    1. [Longest K-good segment](https://codeforces.com/contest/616/problem/D)			
    1. [Nested Ranges Count](https://cses.fi/problemset/task/2169#:~:text=CSES%20%2D%20Nested%20Ranges%20Count&text=Given%20n%20ranges%2C%20your%20task,c%20and%20d%E2%89%A4b.&text=The%20first%20input%20line%20has,n%3A%20the%20number%20of%20ranges.)			
    1. [Rooks Defenders](https://codeforces.com/problemset/problem/1679/C)			
    1. [Matryoshkas](https://codeforces.com/problemset/problem/1790/D)					
    1. [Playing in a casino](https://codeforces.com/problemset/problem/1808/B)		
    1. [Sum of four values](https://cses.fi/problemset/task/1642)				
    1. [Sliding Window Median](https://cses.fi/problemset/task/1076)		
    1. [Sliding Window Cost](https://cses.fi/problemset/task/1077)		
    1. [Fun Problem](https://codeforces.com/contest/1764/problem/G2)
- Optional: Read Chapter-5 of this [Algorithm Design](https://github.com/sakshamrathi21/SOC-Conquering_Competitive_Programming/blob/main/Resources/Algorithm%20Design%20(J.%20Kleinberg%2C%20E.%20Tardos).pdf).








# CSc220-LeetCode-Quiz

4/14/26 Quiz #3

This repository contains solutions LeetCode problems from the CSC 220 Algorithms Quizzes. The objective was to solve the problems, some with restrictions on using the library sort function and to explain how each solution achieves efficient runtime.

## Problem 1: LeetCode #75: Sort Colors

### Algorithm Used
**Counting Sort**

### Explanation
The array only contains three possible values: `0`, `1`, and `2`. Because the range is so small, we count how many times each number appears and then rebuild the array in sorted order.

### Steps
1. Create a count array of size 3
2. Count how many `0`s, `1`s, and `2`s are in the input
3. Overwrite the original array using those counts

### Complexity
- **Time:** O(n)
- **Space:** O(1)

---

## Problem 2: LeetCode #164: Maximum Gap

### Algorithm Used
**Bucket Sort**

### Explanation
The problem requires linear time, so using a normal sort is not allowed. Instead, we divide the number range into buckets. Each bucket keeps track of only its minimum and maximum value.

The maximum gap must appear between two non-empty buckets, so after filling the buckets, we scan through them and compare the minimum of the current bucket with the maximum of the previous non-empty bucket.

### Steps
1. Find the minimum and maximum values in the array
2. Compute bucket size and number of buckets
3. Place each number into its correct bucket
4. Track each bucket’s minimum and maximum
5. Scan buckets to find the largest gap

### Complexity
- **Time:** O(n)

---

4/23/26 Quiz #4

## Problem 1: LeetCode #416: Partition Equal Subset Sum
**Knapsack, Subset Sum**

### Complexity
O(n * target)
n is the number of elements, target is total/2 which at worst is (200 × 100)/2 = 10,000.

---

5/12/26 Quiz #5

## LeetCode #200: Number of Islands

We scan every cell row by row, column by column to check every position once. A '1' (land) is an unvisited island so we increment the counter and start a BFS from there.

We use 2 plain arrays; one for row indices, one for column indices. `front` tracks what to dequeue next, `back` tracks where to enqueue next. When `front` == `back`, the queue is empty and BFS is done.

We set a cell to '0' upon adding it to the queue, not after processing it. If we would wait until processing, multiple neighbors could enqueue the same cell before it gets marked, causing duplicate work or wrong answers.

BFS goes outward one at a time. From each cell it check up, down, left, and right. If a neighbor is in bounds and is land ('1'), we add it to the queue and mark it visited.

BFS finds all cells reachable (connected land) from a starting point. Every time BFS starts from the outer loop, an island gets all its '1's turned into '0's. So the next time the outer loop finds a '1', it will be a new island. The total number of times BFS was triggered = number of islands.

### Complexity
- **Time:** O(m*n)

---

5/19/26 Quiz #6

## Problem 2: Leetcode #787: Cheapest Flights Within K Stops
### Complexity
- **Time:** O(K*E); K+1 iterations over all E edges

## Problem 3: LeetCode #743: Network Delay Time
### Complexity
- **Time:** O(E(log(V))

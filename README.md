# LeetCode Patterns

Holds my solutions to the [LeetCode Patterns problems](https://seanprashad.com/leetcode-patterns/).

## Task 1 (Contains Duplicate)

Given an integer array `nums` return `true` if any value appears at least twice in the array, and return `false` if every element is distinct.

Example:

```text
Input: nums = [1,2,3,1]
Output: true
```

<details>
    <summary>Click here to see a hint</summary>

Hash map.
</details>

## Task 2 (Missing Number)

Given an array nums containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array.

Example:

```text
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
```

<details>
    <summary>Click here to see a hint</summary>

Bitwise operations or formula for the sum of the numbers in the range `[1 .. n]`.
</details>

## Task 3 (Find All Numbers Disappeared in an Array)

Given an array `nums` of `n` integers where `nums[i]` is in the range `[1, n]`, return an array of all the integers in the range `[1, n]` that do not appear in `nums`.

> **Challenge**: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

```text
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
```

<details>
    <summary>Click here to see a hint</summary>

Treat the numbers in the list as indices the elements on which you should negate.
</details>

## Task 4 (Single Number)

Given a non-empty array of integers `nums`, every element appears *twice* except for one. Find that single one.

> **Challenge**: Implement a solution with a **linear runtime** complexity and use only **constant extra space**.

Example:

```text
Input: nums = [2,2,1]
Output: 1
```

<details>
    <summary>Click here to see a hint</summary>

Bitwise operations.
</details>

## Task 5 (Climbing Stairs)

You are climbing a staircase. It takes `n` steps to reach the top. Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?

Example:

```text
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
```

<details>
    <summary>Click here to see a hint</summary>

Reverse fibonacci. Starts from `1` at `n` and at `n - 1` and increases toward `0`.
</details>

## Task 6 (Best Time to Buy and Sell Stock)

You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day. You want to maximize your profit by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock. Return *the maximum profit you can achieve from this transaction*. If you cannot achieve any profit, return `0`.

Example:

```text
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
```

<details>
    <summary>Click here to see a hint</summary>

Sliding window.
</details>

## Task 7 (Maximum Subarray)

Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return *its sum*. A **subarray** is a **contiguous** part of an array.

> **Follow up**: If you have figured out the `O(n)` solution, try coding another solution using the **divide and conquer** approach, which is more subtle.

Example:

```text
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```

<details>
    <summary>Click here to see a hint</summary>

Modified sliding window. Keep a prefix and remove it once it becomes negative.
</details>

## Task 8 (Range Sum Query - Immutable)

Given an integer array `nums`, handle multiple queries of the following type:

1. Calculate the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** where `left <= right`.

Implement the `NumArray` class:

- `NumArray(int[] nums)` Initializes the object with the integer array `nums`.
- `int sumRange(int left, int right)` Returns the sum of the elements of `nums` between indices `left` and `right` inclusive (i.e. `nums[left] + nums[left + 1] + ... + nums[right]`).

> **Challenge**: Implement `sumRange` to run in O(1) time.

Example:

```text
Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]
Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
```

<details>
    <summary>Click here to see a hint</summary>

Dynamic programming - store the sum `[0 .. i]` in an array.
</details>

## Task 9 (Counting Bits)

Given an integer `n`, return an array `ans` of length `n + 1` such that for each `i` (`0 <= i <= n`), `ans[i]` is the number of `1`'s in the binary representation of `i`.

Example:

```text
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
```

<details>
    <summary>Click here to see a hint</summary>

Dynamic programming. No need for bitwise operations.
</details>

## Task 10 (Linked List Cycle)

Given `head`, the head of a linked list, determine if the linked list has a cycle in it. There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to. Note that `pos` is not passed as a parameter.

Example:

```text
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
```

<details>
    <summary>Click here to see a hint</summary>

Fast and slow pointers.
</details>

## Task 11 (Middle of the Linked List)

Given the `head` of a singly linked list, return *the middle node of the linked list*. If there are two middle nodes, return **the second middle** node.

Example:

```text
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
```

<details>
    <summary>Click here to see a hint</summary>

Fast and slow pointers.
</details>

## Task 12 (Palindrome Linked List)

Given the `head` of a singly linked list, return `true` if it is a palindrome.

> **Challenge**: Could you do it in `O(n)` time and `O(1)` space?

Example:

```text
Input: head = [1,2,2,1]
Output: true
```

<details>
    <summary>Click here to see a hint</summary>

Fast and slow pointers.
</details>

## Task 13 (Remove Linked List Elements)

Given the `head` of a linked list and an integer `val`, remove all the nodes of the linked list that have `Node.val == val`, and return *the new head*.

Example:

```text
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
```

<details>
    <summary>Click here to see a hint</summary>

Recursion.
</details>

## Task 14 (Remove Duplicates from Sorted List)

Given the `head` of a sorted linked list, *delete all duplicates such that each element appears only once*. Return *the linked list **sorted** as well*.

Example:

```text
Input: head = [1,1,2]
Output: [1,2]
```

<details>
    <summary>Click here to see a hint</summary>

Fast and slow pointers.
</details>

## Task 15 (Reverse Linked List)

Given the `head` of a singly linked list, reverse the list, and return *the reversed list*.

> **Challenge**: A linked list can be reversed either iteratively or recursively. Could you implement both?

Example:

```text
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
```

<details>
    <summary>Click here to see a hint</summary>

    Pointers.
</details>

## Task 16 (Merge Two Sorted Lists)

You are given the heads of two sorted linked lists `list1` and `list2`. Merge the two lists in a one **sorted** list. The list should be made by splicing together the nodes of the first two lists. Return *the head of the merged linked list*.

Example:

```text
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
```

<details>
    <summary>Click here to see a hint</summary>

Two pointers.
</details>

## Task 17 (Binary Search)

Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index. Otherwise, return `-1`. You must write an algorithm with `O(log n)` runtime complexity.

Example:

```text
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
```

<details>
    <summary>Click here to see a hint</summary>

Two pointers/indices.
</details>

## Task 18 (Find Smallest Letter Greater Than Target)

Given a characters array `letters` that is sorted in **non-decreasing** order and a character `target`, return *the smallest character in the array that is larger than `target`*.

> **Note**: Letters wrap around, i.e. if `target == 'z'` and `letters == ['a', 'b']`, the answer is `'a'`.

Example:

```text
Input: letters = ["c","f","j"], target = "a"
Output: "c"
```

<details>
    <summary>Click here to see a hint</summary>

Binary search.
</details>

## Task 19 (Peak Index in a Mountain Array)

Let's call an array `arr` a **mountain** if the following properties hold:

- `arr.length >= 3`
- There exists some `i` with `0 < i < arr.length - 1` such that:
  - `arr[0] < arr[1] < ... arr[i-1] < arr[i]`
  - `arr[i] > arr[i+1] > ... > arr[arr.length - 1]`

Given an integer array `arr` that is **guaranteed** to be a mountain, return any `i` such that `arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`.

> **Follow up**: Finding the `O(n)` is straightforward, could you find an `O(log(n))` solution?

Example 1:

```text
Input: arr = [0,1,0]
Output: 1
```

Example 2:

```text
Input: arr = [0,10,5,2]
Output: 1
```

<details>
    <summary>Click here to see a hint</summary>

Binary search.
</details>

## Task 20 (Average of Levels in Binary Tree)

Given the `root` of a binary tree, return *the average value of the nodes on each level in the form of an array*.

Example:

```text
Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].
```

<details>
    <summary>Click here to see a hint</summary>

Breadth-first search.
</details>

## Task 21 (Minimum Depth of Binary Tree)

Given a binary tree, find its minimum depth. The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Example:

```text
Input: root = [3,9,20,null,null,15,7]
Output: 2
```

<details>
    <summary>Click here to see a hint</summary>

BFS and/or DFS.
</details>

## Task 22 (Same Tree)

Given the roots of two binary trees `p` and `q`, write a function to check if they are the same or not. Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example:

```text
Input: p = [1,2,3], q = [1,2,3]
Output: true
```

<details>
    <summary>Click here to see a hint</summary>

DFS (recursion).
</details>

## Task 23 (Path Sum)

Given the `root` of a binary tree and an integer `targetSum`, return `true` if the tree has a **root-to-leaf** path such that adding up all the values along the path equals `targetSum`.

Example:

```text
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
```

<details>
    <summary>Click here to see a hint</summary>

DFS (recursion).
</details>

## Task 24 (Maximum Depth of Binary Tree)

Given the `root` of a binary tree, return *its maximum depth*. A binary tree's **maximum depth** is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example:

```text
Input: root = [3,9,20,null,null,15,7]
Output: 3
```

<details>
    <summary>Click here to see a hint</summary>

DFS (recursion).
</details>

## Task 25 (Diameter of Binary Tree)

Given the `root` of a binary tree, return *the length of the **diameter** of the tree*. The **diameter** of a binary tree is the **length** of the longest path between any two nodes in a tree. This path may or may not pass through the `root`. The **length** of a path between two nodes is represented by the number of edges between them.

Example:

```text
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
```

<details>
    <summary>Click here to see a hint</summary>

DFS.
</details>

## Task 26 (Merge Two Binary Trees)

You are given two binary trees `root1` and `root2`. Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree. Return *the merged tree*.

> **Note**: The merging process must start from the root nodes of both trees.

Example:

```text
Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
Output: [3,4,5,5,4,null,7]
```

<details>
    <summary>Click here to see a hint</summary>

DFS.
</details>

## Task 27 (Lowest Common Ancestor of a Binary Search Tree)

Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST. According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).”

Example:

```text
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
```

<details>
    <summary>Click here to see a hint</summary>

DFS.
</details>

## Task 28 (Subtree of Another Tree)

Given the roots of two binary trees `root` and `subRoot`, return `true` if there is a subtree of `root` with the same structure and node values of `subRoot` and `false` otherwise. A subtree of a binary tree `tree` is a tree that consists of a node in `tree` and all of this node's descendants. The tree `tree` could also be considered as a subtree of itself.

Example:

```text
Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
```

<details>
    <summary>Click here to see a hint</summary>

DFS.
</details>

## Task 29 (Invert Binary Tree)

Given the `root` of a binary tree, invert the tree, and return *its root*.

<details>
    <summary>Click here to see a hint</summary>

DFS.
</details>

## Task 30 (Two Sum)

Given an array of integers `nums` and an integer `target`, return *indices of the two numbers such that they add up to `target`*. You may assume that each input would have ***exactly* one solution**, and you may not use the *same* element twice. You can return the answer in any order.

Example:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

<details>
    <summary>Click here to see a hint</summary>

Hash map.
</details>

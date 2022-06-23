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


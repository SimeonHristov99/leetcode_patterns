# LeetCode Patterns

Holds my solutions to the [LeetCode Patterns problems](https://seanprashad.com/leetcode-patterns/).

## Task 1 (Contains Duplicate)

Given an integer array `nums` return `true` if any value appears at least twice in the array, and return `false` if every element is distinct.

Example:

```text
Input: nums = [1,2,3,1]
Output: true
```

## Task 2 (Missing Number)

Given an array nums containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array.

Example:

```text
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
```

## Task 3 (Find All Numbers Disappeared in an Array)

Given an array `nums` of `n` integers where `nums[i]` is in the range `[1, n]`, return an array of all the integers in the range `[1, n]` that do not appear in `nums`.

> **Challenge**: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

```text
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
```

## Task 4 (Single Number)

Given a non-empty array of integers `nums`, every element appears *twice* except for one. Find that single one.

> **Challenge**: Implement a solution with a **linear runtime** complexity and use only **constant extra space**.

Example:

```text
Input: nums = [2,2,1]
Output: 1
```

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


from typing import List

# Time Complexity: O(n)
# Space Complexity: O(n)


class Solution:

    def productExceptSelf(self, nums: List[int]) -> List[int]:
        result = []
        left = []
        right = []

        to_add = 1
        for n in nums:
            left.append(to_add)
            to_add *= n

        to_add = 1
        for n in nums[::-1]:
            right.insert(0, to_add)
            to_add *= n

        for (n, k) in zip(left, right):
            result.append(n * k)

        return result

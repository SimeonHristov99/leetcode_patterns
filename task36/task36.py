from typing import List


class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        len_orig = len(original)

        if m * n != len_orig:
            return []

        result = []
        i = 0
        for rows in range(m):
            result.append(original[i:i+n])
            i += n

        return result

class Solution:

    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        seen_s = {}
        seen_t = {}

        for si, ti in zip(s, t):
            seen_s[si] = seen_s.get(si, 0) + 1
            seen_t[ti] = seen_t.get(ti, 0) + 1

        return seen_s == seen_t

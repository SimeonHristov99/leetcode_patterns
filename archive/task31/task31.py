from typing import List
import unittest


class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end


class Solution:
    """
    @param intervals: an array of meeting time intervals
    @return: if a person could attend all meetings
    """

    def can_attend_meetings(self, intervals: List[Interval]) -> bool:
        intervals = sorted(intervals, key=lambda i: (i.start, i.end))

        for i1, i2 in zip(intervals, intervals[1:]):
            if i2.start < i1.end:
                return False

        return True


class TestMethods(unittest.TestCase):

    def test1(self):
        s = Solution()

        times = [
            Interval(0, 30),
            Interval(5, 10),
            Interval(15, 20),
        ]

        self.assertEqual(False, s.can_attend_meetings(times))

    def test2(self):
        s = Solution()

        times = [
            Interval(0, 8),
            Interval(8, 10),
        ]

        self.assertEqual(True, s.can_attend_meetings(times))

    def test3(self):
        s = Solution()

        times = [
            Interval(5, 8),
            Interval(9, 15),
        ]

        self.assertEqual(True, s.can_attend_meetings(times))


if __name__ == '__main__':
    unittest.main()

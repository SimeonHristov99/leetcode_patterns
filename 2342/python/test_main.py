import unittest

import main


class TestMaximumSum(unittest.TestCase):

    def test_case1(self):
        # Arrange
        nums = [18, 43, 36, 13, 7]
        expected = 54

        # Act
        actual = main.maximum_sum(nums)

        # Assert
        self.assertEqual(actual, expected)

    def test_case2(self):
        # Arrange
        nums = [10, 12, 19, 14]
        expected = -1

        # Act
        actual = main.maximum_sum(nums)

        # Assert
        self.assertEqual(actual, expected)

    def test_case3(self):
        # Arrange
        nums = [
            229, 398, 269, 317, 420, 464, 491, 218, 439, 153, 482, 169, 411, 93, 147, 50, 347, 210,
            251, 366, 401
        ]
        expected = 973  # 491 + 482

        # Act
        actual = main.maximum_sum(nums)

        # Assert
        self.assertEqual(actual, expected)

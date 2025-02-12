import unittest

import main


class TestRemoveOccurrences(unittest.TestCase):

    def test_returns_empty_string_when_input_empty(self):
        # Arrange
        s = ''
        part = 'abc'
        expected = ''

        # Act
        actual = main.remove_occurrences(s, part)

        # Assert
        self.assertEqual(actual, expected)

    def test_returns_non_matching_suffix_when_start_matches_part(self):
        # Arrange
        s = 'abcx'
        part = 'abc'
        expected = 'x'

        # Act
        actual = main.remove_occurrences(s, part)

        # Assert
        self.assertEqual(actual, expected)

    def test_leetcode_case1(self):
        # Arrange
        s = 'daabcbaabcbc'
        part = 'abc'
        expected = 'dab'

        # Act
        actual = main.remove_occurrences(s, part)

        # Assert
        self.assertEqual(actual, expected)

    def test_leetcode_case2(self):
        # Arrange
        s = 'axxxxyyyyb'
        part = 'xy'
        expected = 'ab'

        # Act
        actual = main.remove_occurrences(s, part)

        # Assert
        self.assertEqual(actual, expected)

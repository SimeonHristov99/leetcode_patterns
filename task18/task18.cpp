#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include <vector>

class Solution
{
public:
    char nextGreatestLetter(std::vector<char> &letters, char target)
    {
        char last_seen = '1';
        int len_letters = letters.size();

        int l = 0;
        int u = len_letters - 1;

        int mid = l + (u - l) / 2;

        while (l <= u)
        {
            mid = l + (u - l) / 2;

            if (letters[mid] > target)
            {
                while (mid >= 0 && letters[mid] > target)
                {
                    last_seen = letters[mid];
                    --mid;
                }
                return letters[mid + 1];
            }

            l = mid + 1;
        }

        return last_seen == '1' ? letters[(mid + 1) % len_letters] : last_seen;
    }
};

TEST_CASE("Example 1")
{
    Solution s;
    std::vector<char> letters{'c', 'f', 'j'};
    char target = 'a';

    char expected = 'c';

    char result = s.nextGreatestLetter(letters, target);

    CHECK_EQ(result, expected);
}

TEST_CASE("Example 2")
{
    Solution s;
    std::vector<char> letters{'c', 'f', 'j'};
    char target = 'c';

    char expected = 'f';

    char result = s.nextGreatestLetter(letters, target);

    CHECK_EQ(result, expected);
}

TEST_CASE("Example 3")
{
    Solution s;
    std::vector<char> letters{'c', 'f', 'j'};
    char target = 'd';

    char expected = 'f';

    char result = s.nextGreatestLetter(letters, target);

    CHECK_EQ(result, expected);
}

TEST_CASE("Example 4")
{
    Solution s;
    std::vector<char> letters{'c', 'f', 'j'};
    char target = 'j';

    char expected = 'c';

    char result = s.nextGreatestLetter(letters, target);

    CHECK_EQ(result, expected);
}

TEST_CASE("Example 5")
{
    Solution s;
    std::vector<char> letters{'e', 'e', 'e', 'e', 'e', 'e', 'n', 'n', 'n', 'n'};
    char target = 'e';

    char expected = 'n';

    char result = s.nextGreatestLetter(letters, target);

    CHECK_EQ(result, expected);
}

TEST_CASE("Example 6")
{
    Solution s;
    std::vector<char> letters{'e', 'e', 'e', 'k', 'q', 'q', 'q', 'v', 'v', 'y'};
    char target = 'e';

    char expected = 'k';

    char result = s.nextGreatestLetter(letters, target);

    CHECK_EQ(result, expected);
}

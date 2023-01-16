#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include <vector>

class Solution
{
private:
    int population_count(int n)
    {
        int ones = 0;

        while (n > 0)
        {
            ones += n & 1;
            n >>= 1;
        }

        return ones;
    }

public:
    std::vector<int> countBits(int n)
    {
        std::vector<int> result;

        for (int i = 0; i < n + 1; ++i)
        {
            result.push_back(
                population_count(i)
            );
        }

        return result;
    }
};

TEST_CASE("Example 1")
{
    Solution obj;
    std::vector<int> res = obj.countBits(2);
    std::vector<int> expected{0, 1, 1};
    CHECK_EQ(res, expected);
}

TEST_CASE("Example 2")
{
    Solution obj;
    std::vector<int> res = obj.countBits(5);
    std::vector<int> expected{0, 1, 1, 2, 1, 2};
    CHECK_EQ(res, expected);
}

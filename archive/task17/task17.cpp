#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include <vector>

class Solution
{
public:
    int search(std::vector<int> &nums, const int target)
    {
        int nums_len = nums.size();
        if (nums_len == 0)
        {
            return false;
        }

        int l = 0;
        int u = nums_len - 1;

        int mid = -1;

        while (l <= u)
        {
            mid = (u + l) / 2;
            if (nums[mid] == target)
            {
                // target is equal to mid
                return mid;
            }

            if (nums[mid] < target)
            {
                // target is bigger than mid
                l = mid + 1;
            }
            else
            {
                // target is less than mid
                u = mid - 1;
            }
        }

        return -1;
    }
};

TEST_CASE("Example 1")
{
    Solution s;
    std::vector<int> nums{-1, 0, 3, 5, 9, 12};
    int target = 9;

    int expected = 4;

    int result = s.search(nums, target);

    CHECK_EQ(result, expected);
}

TEST_CASE("Example 2")
{
    Solution s;
    std::vector<int> nums{-1, 0, 3, 5, 9, 12};
    int target = 7;

    int expected = -1;

    int result = s.search(nums, target);

    CHECK_EQ(result, expected);
}

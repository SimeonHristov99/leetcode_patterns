#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        int nums_len = nums.size();
        std::unordered_map<int, int> diffs;

        // std::unordered_map<int, int>

        for (int i = 0; i < nums_len; ++i)
        {
            auto el = diffs.find(nums[i]);

            if (el != diffs.end())
            {
                return {el->second, i};
            }

            diffs.insert({target - nums[i], i});
        }

        return {};
    }
};

TEST_CASE("Example 1")
{
    Solution s;

    std::vector<int> nums{2, 7, 11, 15};
    int target = 9;

    std::vector<int> expected{0, 1};

    std::vector<int> result = s.twoSum(nums, target);

    CHECK_EQ(result, expected);
}

TEST_CASE("Example 2")
{
    Solution s;

    std::vector<int> nums{3, 2, 4};
    int target = 6;

    std::vector<int> expected{1, 2};

    std::vector<int> result = s.twoSum(nums, target);

    CHECK_EQ(result, expected);
}

TEST_CASE("Example 3")
{
    Solution s;

    std::vector<int> nums{3, 3};
    int target = 6;

    std::vector<int> expected{0, 1};

    std::vector<int> result = s.twoSum(nums, target);

    CHECK_EQ(result, expected);
}

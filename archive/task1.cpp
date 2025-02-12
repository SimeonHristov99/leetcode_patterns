#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include <set>

bool contains_duplicate(int arr[], const int size)
{
    std::set<int> seen;

    for (int i = 0; i < size; ++i)
    {
        if (seen.find(arr[i]) != seen.end())
        {
            return true;
        }

        seen.insert(arr[i]);
    }

    return false;
}

TEST_CASE("Example 1")
{
    int nums[32] = {1, 2, 3, 1};
    CHECK(contains_duplicate(nums, 4));
}

TEST_CASE("Example 2")
{
    int nums[32] = {1, 2, 3, 4};
    CHECK_FALSE(contains_duplicate(nums, 4));
}

TEST_CASE("Example 3")
{

    int nums[32] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    CHECK(contains_duplicate(nums, 10));
}
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

int missing_number(int arr[], int size)
{
    int sum = 0;
    int goal_sum = size * (size + 1) / 2;

    for (int i = 0; i < size; ++i)
    {
        sum += arr[i];
    }

    return goal_sum - sum;
}

TEST_CASE("Example 1")
{
    int nums[32] = {3, 0, 1};
    CHECK_EQ(missing_number(nums, 3), 2);
}

TEST_CASE("Example 2")
{
    int nums[32] = {0, 1};
    CHECK_EQ(missing_number(nums, 2), 2);
}

TEST_CASE("Example 3")
{
    int nums[32] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    CHECK_EQ(missing_number(nums, 9), 8);
}
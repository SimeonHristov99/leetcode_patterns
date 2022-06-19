#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

int max_sub_array(int nums[], const int size)
{
    if (size < 1)
    {
        return 0;
    }

    int max_sum = nums[0];
    int prefix = max_sum;

    for (int i = 1; i < size; ++i)
    {
        prefix = (prefix < 0 ? nums[i] : prefix + nums[i]);
        max_sum = (max_sum > prefix ? max_sum : prefix);
    }

    return max_sum;
}

TEST_CASE("Example 1")
{
    int arr[32] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    CHECK_EQ(max_sub_array(arr, 9), 6);
}

TEST_CASE("Example 2")
{
    int arr[32] = {1};
    CHECK_EQ(max_sub_array(arr, 1), 1);
}

TEST_CASE("Example 3")
{
    int arr[32] = {5, 4, -1, 7, 8};
    CHECK_EQ(max_sub_array(arr, 5), 23);
}

TEST_CASE("Example 4")
{
    int arr[32] = {-1, -2};
    CHECK_EQ(max_sub_array(arr, 2), -1);
}

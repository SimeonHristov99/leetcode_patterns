#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

int max_profit(int prices[], const int size)
{
    int result = 0;

    int min_idx = 0;
    int max_idx = 1;

    while (max_idx < size)
    {
        int current_diff = prices[max_idx] - prices[min_idx];

        if (prices[max_idx] < prices[min_idx])
        {
            min_idx = max_idx;
        }
        else if (current_diff > result)
        {
            result = current_diff;
        }

        ++max_idx;
    }

    return result;
}

TEST_CASE("Example 1")
{
    int arr[32] = {7, 1, 5, 3, 6, 4};
    CHECK_EQ(max_profit(arr, 6), 5);
}

TEST_CASE("Example 2")
{
    int arr[32] = {7, 6, 4, 3, 1};
    CHECK_EQ(max_profit(arr, 5), 0);
}

TEST_CASE("Example 3")
{
    int arr[32] = {2, 4, 1};
    CHECK_EQ(max_profit(arr, 3), 2);
}

TEST_CASE("Example 4")
{
    int arr[32] = {3, 2, 6, 5, 0, 3};
    CHECK_EQ(max_profit(arr, 6), 4);
}

TEST_CASE("Example 5")
{
    int arr[32] = {2, 1};
    CHECK_EQ(max_profit(arr, 2), 0);
}

TEST_CASE("Example 6")
{
    int arr[32] = {2, 1, 2, 1, 0, 0, 1};
    CHECK_EQ(max_profit(arr, 7), 1);
}

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

int single_number(int arr[], const int size)
{
    int result = 0;

    for (int i = 0; i < size; ++i)
    {
        result ^= arr[i];
    }

    return result;
}

TEST_CASE("Example 1")
{
    int arr[32] = {2, 2, 1};
    CHECK_EQ(single_number(arr, 3), 1);
}
TEST_CASE("Example 2")
{
    int arr[32] = {4, 1, 2, 1, 2};
    CHECK_EQ(single_number(arr, 5), 4);
}
TEST_CASE("Example 3")
{
    int arr[32] = {1};
    CHECK_EQ(single_number(arr, 1), 1);
}

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include <set>

void find_disappeared_numbers(int arr[], int size, int result[])
{
    int j = 0;
    std::set<int> seen;

    for (int i = 0; i < size; ++i)
    {
        seen.insert(arr[i]);
    }

    for (int i = 1; i <= size; ++i)
    {
        if (seen.find(i) == seen.end())
        {
            result[j++] = i;
        }
    }
}

TEST_CASE("Example 1")
{
    int nums[32] = {4, 3, 2, 7, 8, 2, 3, 1};
    int result[32];

    find_disappeared_numbers(nums, 8, result);

    CHECK_EQ(result[0], 5);
    CHECK_EQ(result[1], 6);
}

TEST_CASE("Example 2")
{
    int nums[32] = {1, 1};
    int result[32];

    find_disappeared_numbers(nums, 2, result);

    CHECK_EQ(result[0], 2);
}

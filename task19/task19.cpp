#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include <vector>

class Solution
{
public:
    int peakIndexInMountainArray(std::vector<int> &arr)
    {
        int l = 0;
        int len_arr = arr.size();
        int u = len_arr;

        while (l <= u)
        {
            int mid = l + (u - l) / 2;

            if (mid - 1 >= 0 && mid + 1 < len_arr && arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            {
                return mid;
            }

            if (arr[mid] < arr[mid + 1])
            {
                l = mid + 1;
            }
            else
            {
                u = mid - 1;
            }
        }

        return -1;
    }
};

TEST_CASE("Example 1")
{
    Solution s;
    std::vector<int> arr{0, 1, 0};
    char expected = 1;
    char result = s.peakIndexInMountainArray(arr);
    CHECK_EQ(result, expected);
}

TEST_CASE("Example 2")
{
    Solution s;
    std::vector<int> arr{0, 2, 1, 0};
    char expected = 1;
    char result = s.peakIndexInMountainArray(arr);
    CHECK_EQ(result, expected);
}

TEST_CASE("Example 3")
{
    Solution s;
    std::vector<int> arr{0, 10, 5, 2};
    char expected = 1;
    char result = s.peakIndexInMountainArray(arr);
    CHECK_EQ(result, expected);
}

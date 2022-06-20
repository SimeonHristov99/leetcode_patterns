#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include <vector>

class NumArray
{
private:
    std::vector<int> m_nums;

public:
    NumArray(const std::vector<int> &nums)
    {
        int sum = 0;
        m_nums.push_back(sum);

        for (const int n : nums)
        {
            sum += n;
            m_nums.push_back(sum);
        }
    }

    int sumRange(int left, int right)
    {
        return m_nums[right + 1] - m_nums[left];
    }
};

TEST_CASE("Example 1")
{
    NumArray *obj = new NumArray({-2, 0, 3, -5, 2, -1});
    int param_1 = obj->sumRange(0, 2);
    CHECK_EQ(param_1, 1);
}

TEST_CASE("Example 2")
{
    NumArray *obj = new NumArray({-2, 0, 3, -5, 2, -1});
    int param_1 = obj->sumRange(2, 5);
    CHECK_EQ(param_1, -1);
}

TEST_CASE("Example 3")
{
    NumArray *obj = new NumArray({-2, 0, 3, -5, 2, -1});
    int param_1 = obj->sumRange(0, 5);
    CHECK_EQ(param_1, -3);
}

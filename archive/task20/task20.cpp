#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    void getLevel(TreeNode *current, size_t level, std::vector<double> &result)
    {
        if (!current)
        {
            return;
        }

        if (level == 0)
        {
            result.push_back(current->val);
        }

        getLevel(current->left, level - 1, result);
        getLevel(current->right, level - 1, result);
    }

    double avg(const std::vector<double> &nums)
    {
        double result = 0;

        for (const double n : nums)
        {
            result += n;
        }

        return result / nums.size();
    }

public:
    std::vector<double> averageOfLevels(TreeNode *root)
    {
        std::vector<double> result;
        std::vector<double> nodesAtLvlK;
        int i = 0;

        while (true)
        {
            getLevel(root, i, nodesAtLvlK);

            if (nodesAtLvlK.size() == 0)
            {
                return result;
            }

            result.push_back(avg(nodesAtLvlK));
            nodesAtLvlK.clear();
            ++i;
        }
    }
};

TEST_CASE("Example 1")
{
    Solution s;

    TreeNode *t1 = new TreeNode(3);
    TreeNode *t2 = new TreeNode(9);
    TreeNode *t3 = new TreeNode(20);
    TreeNode *t4 = new TreeNode(15);
    TreeNode *t5 = new TreeNode(7);

    t1->left = t2;
    t1->right = t3;
    t3->left = t4;
    t3->right = t5;

    std::vector<double> expected{3, 14.5, 11};
    std::vector<double> result = s.averageOfLevels(t1);

    size_t len_expected = expected.size();
    for (int i = 0; i < len_expected; ++i)
    {
        CHECK_EQ(result[i], expected[i]);
    }
}

TEST_CASE("Example 2")
{
    Solution s;

    TreeNode *t1 = new TreeNode(3);
    TreeNode *t2 = new TreeNode(9);
    TreeNode *t3 = new TreeNode(20);
    TreeNode *t4 = new TreeNode(15);
    TreeNode *t5 = new TreeNode(7);

    t1->left = t2;
    t2->left = t4;
    t2->right = t5;
    t1->right = t3;

    std::vector<double> expected{3, 14.5, 11};
    std::vector<double> result = s.averageOfLevels(t1);

    size_t len_expected = expected.size();
    for (int i = 0; i < len_expected; ++i)
    {
        CHECK_EQ(result[i], expected[i]);
    }
}

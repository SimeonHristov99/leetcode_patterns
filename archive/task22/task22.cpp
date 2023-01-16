#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include <vector>
#include <queue>

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
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
        {
            return true;
        }

        if (!p && q || p && !q)
        {
            return false;
        }

        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

TEST_CASE("Example 1")
{
    Solution s;

    TreeNode *t11 = new TreeNode(1);
    TreeNode *t12 = new TreeNode(2);
    TreeNode *t13 = new TreeNode(3);

    TreeNode *t21 = new TreeNode(1);
    TreeNode *t22 = new TreeNode(2);
    TreeNode *t23 = new TreeNode(3);

    t11->left = t12;
    t11->right = t13;

    t21->left = t22;
    t21->right = t23;

    int expected = true;
    int result = s.isSameTree(t11, t21);

    CHECK_EQ(result, expected);
}

TEST_CASE("Example 2")
{
    Solution s;

    TreeNode *t11 = new TreeNode(1);
    TreeNode *t12 = new TreeNode(2);

    TreeNode *t21 = new TreeNode(1);
    TreeNode *t22 = new TreeNode(2);

    t11->left = t12;

    t21->right = t22;

    int expected = false;
    int result = s.isSameTree(t11, t21);

    CHECK_EQ(result, expected);
}

TEST_CASE("Example 3")
{
    Solution s;

    TreeNode *t11 = new TreeNode(1);
    TreeNode *t12 = new TreeNode(2);
    TreeNode *t13 = new TreeNode(3);

    TreeNode *t21 = new TreeNode(1);
    TreeNode *t22 = new TreeNode(2);
    TreeNode *t23 = new TreeNode(1);

    t11->left = t12;
    t11->right = t13;

    t21->left = t22;
    t21->right = t23;

    int expected = false;
    int result = s.isSameTree(t11, t21);

    CHECK_EQ(result, expected);
}

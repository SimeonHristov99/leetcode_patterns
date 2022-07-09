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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return false;
        }

        if (!root->left && !root->right)
        {
            return targetSum == root->val;
        }

        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

TEST_CASE("Example 1")
{
    Solution s;

    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(4);
    TreeNode *t3 = new TreeNode(11);
    TreeNode *t4 = new TreeNode(7);
    TreeNode *t5 = new TreeNode(2);
    TreeNode *t6 = new TreeNode(8);
    TreeNode *t7 = new TreeNode(13);
    TreeNode *t8 = new TreeNode(4);
    TreeNode *t9 = new TreeNode(1);

    t1->left = t2;
    t1->right = t6;
    t2->left = t3;
    t3->left = t4;
    t3->right = t5;
    t6->left = t7;
    t6->right = t8;
    t8->right = t9;

    int expected = true;
    int targetSum = 22;
    int result = s.hasPathSum(t1, targetSum);

    CHECK_EQ(result, expected);
}

TEST_CASE("Example 2")
{
    Solution s;

    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(3);

    t1->left = t2;
    t1->right = t3;

    int expected = false;
    int targetSum = 0;
    int result = s.hasPathSum(t1, targetSum);

    CHECK_EQ(result, expected);
}

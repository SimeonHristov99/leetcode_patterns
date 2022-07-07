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
    int minDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int leftD = minDepth(root->left);
        int rightD = minDepth(root->right);

        if (leftD == 0)
        {
            return 1 + rightD;
        }

        if (rightD == 0)
        {
            return 1 + leftD;
        }

        return 1 + std::min(rightD, leftD);
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

    int expected = 2;
    int result = s.minDepth(t1);

    CHECK_EQ(result, expected);
}

TEST_CASE("Example 2")
{
    Solution s;

    TreeNode *t1 = new TreeNode(2);
    TreeNode *t2 = new TreeNode(3);
    TreeNode *t3 = new TreeNode(4);
    TreeNode *t4 = new TreeNode(5);
    TreeNode *t5 = new TreeNode(6);

    t1->right = t2;
    t2->right = t3;
    t3->right = t4;
    t4->right = t5;

    int expected = 5;
    int result = s.minDepth(t1);

    CHECK_EQ(result, expected);
}

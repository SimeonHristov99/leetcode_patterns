/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    int height(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        return 1 + std::max(height(root->left), height(root->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        return std::max(
            {
                height(root->left) + height(root->right),
                diameterOfBinaryTree(root->left),
                diameterOfBinaryTree(root->right)
                }
        );
    }
};
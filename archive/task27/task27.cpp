/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) {
            return nullptr;
        }
        
        if(
            p->val <= root->val && root->val <= q->val
            || q->val <= root->val && root->val <= p->val
        ) {
            return root;
        }
        
        TreeNode* inLeft = lowestCommonAncestor(root->left, p, q);
        
        if(inLeft) {
            return inLeft;
        }
        
        return lowestCommonAncestor(root->right, p, q);
    }
};

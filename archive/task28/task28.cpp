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
    bool isSubtreeHelper(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) {
            return true;
        }
        
        if(!root && subRoot || root && !subRoot) {
            return false;
        }
        
        return root->val == subRoot->val
            && isSubtreeHelper(root->left, subRoot->left)
            && isSubtreeHelper(root->right, subRoot->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot, bool found=false) {
        if(!root && !subRoot) {
            return true;
        }
        
        if(!root && subRoot || root && !subRoot) {
            return false;
        }
        
        if(root->val == subRoot->val) {
            return isSubtreeHelper(root, subRoot)
                || isSubtree(root->left, subRoot) && !isSubtree(root->right, subRoot)
                || isSubtree(root->right, subRoot) && !isSubtree(root->left, subRoot)
                || isSubtree(root->right, subRoot) && isSubtree(root->left, subRoot);
        }
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
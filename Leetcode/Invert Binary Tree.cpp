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
    void helper(TreeNode* root){
        swap(root->left,root->right);
        
        if (root->left != NULL)
            helper(root->left);
        if (root->right != NULL)
            helper(root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root != NULL)
            helper(root);
        return root;
    }
    
    
    
};
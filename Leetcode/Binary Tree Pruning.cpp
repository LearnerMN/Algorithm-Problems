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
    
    bool prune(TreeNode* root){
        if (root == NULL)
            return false;
        if (root->val == 0 && root->left == NULL && root->right == NULL){
            return true;
        }
        bool result = false;
        result |= prune(root->left);
        result |= prune(root->right);
        return result;
    }
    
    TreeNode* helper(TreeNode* root){
        if (root == NULL)
            return root;
        
        if (root->val == 0 && root->left == NULL && root->right == NULL){
            return NULL;
        }
        
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        
        return root;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        
        
        while (prune(root)){
            root = helper(root);
        }
        return root;
    }
};
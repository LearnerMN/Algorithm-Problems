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
private:
    int helper(TreeNode* root, bool isLeft){
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL){
            if(isLeft){
                return root->val;
            }
            return 0;
        }
        return helper(root->left, true) + helper(root->right, false);
    } 
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }
};
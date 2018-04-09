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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root != NULL && sum - root->val == 0 && root->left == NULL && root->right == NULL){
            return true;
        }
        if (root == NULL){
            return false;
        }
        bool check = false;
        if (root->left != NULL){
            check |= hasPathSum(root->left, sum - root->val);
        }
        if (root->right != NULL){
            check |= hasPathSum(root->right, sum - root->val);
        }
        return check;
    }
};
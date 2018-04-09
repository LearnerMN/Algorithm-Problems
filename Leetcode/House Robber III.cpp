/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
struct hos{
    int prevMax = 0;
    int currentMax = 0;
};
class Solution {
    hos helper(TreeNode* root){
        hos res;
        if (root == NULL)
            return res;
        
        hos left = helper(root->left);
        hos right = helper(root->right);
        
        res.prevMax = left.currentMax + right.currentMax;
        res.currentMax = max(res.prevMax,root->val + left.prevMax + right.prevMax);
        return res;
    }
public:
    int rob(TreeNode* root) {
        return helper(root).currentMax;
    }
};
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
    bool check(TreeNode* r1, TreeNode* r2){
        if (r1 == NULL && r2 == NULL)
            return true;
        
        if (r1 == NULL || r2 == NULL)
            return false;
        
        return r1->val == r2->val 
            && check(r1->left, r2->right) 
            && check(r1->right, r2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};
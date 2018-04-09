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
    void helper(TreeNode* root, int &k,int &m){
        if (root == NULL)
            return;
        helper(root->left,k,m);
        if (k-- > 0)
            m = root->val;
        // else
            // return;
        helper(root->right,k,m);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int m = root == NULL ? 0 : root->val;
        helper(root,k,m);
        return m;
    }

};
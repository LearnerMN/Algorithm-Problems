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
    void preO(TreeNode* root, vector< int > &v){
        if (root != NULL){
            v.push_back(root->val);
            preO(root->left, v);
            preO(root->right, v);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector< int > res;
        preO(root, res);
        return res;
    }
};
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
    void postO(TreeNode* root, vector< int > &v){
        if (root != NULL){
            postO(root->left, v);
            postO(root->right, v);
            v.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postO(root, res);
        return res;
    }
};
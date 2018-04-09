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
    
    void helper(vector< string > &v,vector< int > &values,TreeNode* node){
        values.push_back(node->val);
        if (node->left != NULL || node->right != NULL){
            if (node->left != NULL){
                helper(v,values,node->left); 
                values.pop_back();
            }
            if (node->right != NULL){
                helper(v,values,node->right);
                values.pop_back();
            }
        }else{
            string st = "";
            for (int i=0; i<values.size(); i++){
                if (i != 0)
                    st += "->";
                st += to_string(values[i]);
            }
            v.push_back(st);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        vector< int > values;
        if (root != NULL)
            helper(v,values,root);
        return v;
    }
};
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue< pair<TreeNode*,int > > q;
        if (root != NULL){
            q.push(make_pair(root, 1));
        }
        vector< vector< int > > res;
        while (!q.empty()){
            pair< TreeNode*,int > p = q.front();
            q.pop();
            if (res.size() < p.second){
                vector< int > tmp;
                tmp.push_back(p.first->val);
                res.push_back(tmp);
            }else{
                res[p.second-1].push_back(p.first->val);    
            }
            
            if (p.first->left != NULL){
                q.push(make_pair(p.first->left,p.second+1));
            }
            if (p.first->right != NULL){
                q.push(make_pair(p.first->right,p.second+1));
            }
        }
        return res;
    }
};
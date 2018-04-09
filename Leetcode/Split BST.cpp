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
    TreeNode* search(TreeNode* root, int V){
        if (root == NULL || root->val == V){
            return NULL;
        }
        cout<<root->val<<endl;
        return root->val > V ? search(root->left, V) : search(root->right, V);
    }
    
    TreeNode* insert(TreeNode* root, int V){
        if (root == NULL){
            TreeNode *temp = new TreeNode(V);
            return temp;
        }
        if (V < root->val)
            root->left  = insert(root->left, V);
        else if (V > root->val)
            root->right = insert(root->right, V); 
        else;
        
        return root;
    }
    void prefix(TreeNode* root, TreeNode* one, TreeNode* two, int V){
        if (root != NULL){
            if (root->val <= V){
                one = insert(one, root->val);
            }else if (root->val > V){
                two = insert(two, root->val);
            }
            prefix(root->left, one, two, V);
            prefix(root->right, one, two, V);
        }
    }
public:
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        vector<TreeNode*> res;
        TreeNode* one = new TreeNode(INT_MAX);
        TreeNode* two = new TreeNode(INT_MAX);
        prefix(root, one, two, V);
        res.push_back(one->left);
        res.push_back(two->left);
        return res;
    }
};
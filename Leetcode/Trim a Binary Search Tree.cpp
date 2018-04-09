/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode trimBST(TreeNode root, int L, int R) {
        return helper(null, root, L, R, false);
    }
    
    TreeNode helper(TreeNode parent, TreeNode root, int L, int R, boolean isLeft){
        if (root == null){
            return root;
        }
        if (root.val < L){
            if (parent != null && isLeft){
                parent.left = root.right;
                root = parent.left;
                return helper(parent, parent.left, L, R,true);
            }else if (parent == null){
                return helper(null, root.right, L, R,true);
            }
        }else if (root.val > R){
            if (parent != null && !isLeft){
                parent.right = root.left;
                root = parent.right;
                return helper(parent, parent.right, L, R,false);
            }else if (parent == null){
                return helper(null, root.left, L, R,false);
            }
        }else{
            root.left = helper(root, root.left, L, R, true);
            root.right = helper(root, root.right, L, R, false);
        }
        return root;
    }
}
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null || root.left == null && root.right == null) {
            return 0;
        }
        return sumOfTree(root.left, true) + sumOfTree(root.right, false);
    }
    
    private int sumOfTree(TreeNode root, boolean isLeftChild) {
        if (root == null) {
            return 0;
        }
        if (root.left == null && root.right == null) {
            if (isLeftChild) {
                return root.val;
            } else {
                return 0;
            }
        }
        return sumOfTree(root.left, true) + sumOfTree(root.right, false);
    }
}

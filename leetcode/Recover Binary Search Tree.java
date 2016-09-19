/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
	TreeNode pre = null;
	TreeNode n1 = null, n2 = null;
	
	public void solve(TreeNode root) {
		if (root.left != null)
			solve(root.left);
		if (pre != null) {
			if (pre.val > root.val) {
				if (n1 == null) {
					n1 = pre;
					n2 = root;
				} else {
					n2 = root;
				}
			}
		}
		pre = root;
		if (root.right != null)
			solve(root.right);
	}
	
	public void recoverTree(TreeNode root) {
		solve(root);
		int t = n1.val;
		n1.val = n2.val;
		n2.val = t;
	}
}

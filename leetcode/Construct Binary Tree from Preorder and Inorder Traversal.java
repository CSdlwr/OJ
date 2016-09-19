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
	public TreeNode buildTree(int[] preorder, int[] inorder) {
		return solve(preorder, 0, preorder.length-1, inorder, 0, inorder.length-1);
	}
	
	public TreeNode solve(int[] pre, int ps, int pe, 
			int[] in, int is, int ie) {
		if (ps > pe) return null;
		TreeNode root = new TreeNode(pre[ps]);
		int ri = is;
		while (in[ri] != pre[ps]) ri++;
		int n = ri-is;
		root.left = solve(pre, ps+1, ps+n, in, is, ri-1);
		root.right = solve(pre, ps+n+1, pe, in, ri+1, ie);
		return root;
	}
}

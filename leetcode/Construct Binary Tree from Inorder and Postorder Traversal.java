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
	public TreeNode buildTree(int[] inorder, int[] postorder) {
		return solve(inorder, 0, inorder.length-1, postorder, 0, postorder.length-1);
	}
	
	public TreeNode solve(int[] in, int is, int ie,
			int[] pos, int ps, int pe) {
		if (ps > pe) return null;
		TreeNode root = new TreeNode(pos[pe]);
		int ri = is;
		while (in[ri] != pos[pe]) ++ri;
		int n = ri-is;
		root.left = solve(in, is, ri-1, pos, ps, ps+n-1);
		root.right = solve(in, ri+1, ie, pos, ps+n, pe-1);
		return root;
	}
}

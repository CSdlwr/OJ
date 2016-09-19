/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; left = null; right = null; }
 * }
 */
public class Solution {
	public List<TreeNode> solve(int x, int y) {
		List<TreeNode> rtn = new ArrayList<TreeNode>();
		if (x > y) {
			rtn.add(null); 
			return rtn;
		}
		for (int i = x; i <= y; ++i) {
			List<TreeNode> lr = solve(x, i-1);
			List<TreeNode> rr = solve(i+1, y);
			for (TreeNode l : lr) {
				for (TreeNode r : rr) {
					TreeNode root = new TreeNode(i);
					root.left = l;
					root.right = r;
					rtn.add(root);
				}
			}
		}
		return rtn;
	}
	
	public List<TreeNode> generateTrees(int n) {
		return solve(1, n);
	}
}

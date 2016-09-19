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
    public List<Integer> postorderTraversal(TreeNode root) {
		List<Integer> rtn = new ArrayList<Integer>();
		if (root == null) return rtn;
		Stack<TreeNode> sk1 = new Stack<TreeNode>();
		Stack<TreeNode> sk2 = new Stack<TreeNode>();
		sk1.push(root);
		TreeNode cur = null;
		while (!sk1.empty()) {
			cur = sk1.pop();
			if (cur.left != null) sk1.push(cur.left);
			if (cur.right != null) sk1.push(cur.right);
			sk2.push(cur);
		}
		while (!sk2.empty()) rtn.add(sk2.pop().val);
		return rtn;
    }
}

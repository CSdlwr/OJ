/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

public class BSTIterator {

	Stack<TreeNode> st = new Stack<TreeNode>();
	
	public BSTIterator(TreeNode root) {
		TreeNode cur = root;
		while (cur != null) {
			st.add(cur);
			cur = cur.left;
		}
	}
	
	public boolean hasNext() {
		return !st.isEmpty();
	}
	
	public int next() {
		TreeNode cur = st.pop();
		int ans = cur.val;
		cur = cur.right;
		while (cur != null) {
			st.add(cur);
			cur = cur.left;
		}
		return ans;
	}
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = new BSTIterator(root);
 * while (i.hasNext()) v[f()] = i.next();
 */

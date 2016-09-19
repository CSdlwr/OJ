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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
		List<List<Integer>> re = new ArrayList<List<Integer>>();
		if (root == null) return re;
		List<Integer> ls = new ArrayList<Integer>();
		Stack<List<Integer>> st = new Stack<List<Integer>>();
		Queue<TreeNode> que = new LinkedList<TreeNode>();
		que.add(root);
		int ccnt = 1, ncnt = 0;
		TreeNode cur = null;
		while (que.size() > 0) {
			cur = que.poll(); ls.add(cur.val);
			if (cur.left != null) { que.add(cur.left); ++ncnt; }
			if (cur.right != null) { que.add(cur.right); ++ncnt; }
			if (--ccnt == 0) {
				ccnt = ncnt; ncnt = 0; st.add(ls);
				ls = new ArrayList<Integer>();
			}
		}
		while (!st.empty()) re.add(st.pop());
		return re;
    }
}

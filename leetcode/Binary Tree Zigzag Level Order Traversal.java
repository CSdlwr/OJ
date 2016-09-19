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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
		List<List<Integer>> rtn = new ArrayList<List<Integer>>();
		List<Integer> ls = null;
		if (root == null) return rtn;
		int ans[] = new int[1000];
		Queue<TreeNode> que = new LinkedList<TreeNode>();
		que.add(root);
		int ccnt = 1, ncnt = 0, acnt = 0;
		TreeNode cur = null;
		boolean odr = true;
		while (que.size() > 0) {
			cur = que.poll(); ans[acnt++] = cur.val;
			if (cur.left != null) { que.add(cur.left); ++ncnt; }
			if (cur.right != null) { que.add(cur.right); ++ncnt; }
			if (--ccnt == 0) {
				ls = new ArrayList<Integer>();
				if (odr) for (int i = 0; i < acnt; ++i) ls.add(ans[i]);
				else for (int i = acnt-1; i >= 0; --i) ls.add(ans[i]);
				odr = !odr; rtn.add(ls);
				ccnt = ncnt; ncnt = acnt = 0;
			}
		}
		return rtn;
    }
}

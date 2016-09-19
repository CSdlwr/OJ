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
	List<List<Integer>> ret;
	List<Integer> ls;
	int num[];
	int sum;
	
	public List<List<Integer>> pathSum(TreeNode root, int sum) {
		ret = new ArrayList<List<Integer>>();
		if (root == null) return ret;
		num = new int[1000]; this.sum = sum;
		solve(root, num, 0, 0);
		return ret;
	}
	
	public void solve(TreeNode root, int num[], int cur, int csum) {
		if (root.left == null && root.right == null && csum+root.val == sum) {
			ls = new ArrayList<Integer>();
			for (int i = 0; i < cur; ++i) ls.add(num[i]);
			ls.add(root.val); ret.add(ls); return ;
		}
		num[cur] = root.val;
		if (root.left != null) solve(root.left, num, cur+1, csum+root.val);
		if (root.right != null) solve(root.right, num, cur+1, csum+root.val);
	}
}

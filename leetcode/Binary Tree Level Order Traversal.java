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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> re = new ArrayList<List<Integer>>();
        if (root == null) return re;
        Queue<TreeNode> que = new LinkedList<TreeNode>();
        int ccnt = 0, ncnt = 0;
        que.add(root); ++ccnt;
        List<Integer> l = new ArrayList<Integer>();
        TreeNode t = null;
        while (que.size() != 0) {
        	t = que.poll(); l.add(t.val);
        	if (t.left != null) { que.add(t.left); ++ncnt; }
        	if (t.right != null) { que.add(t.right); ++ncnt; }
        	if (--ccnt == 0) {
        		ccnt = ncnt; ncnt = 0;
        		re.add(l); l = new ArrayList<Integer>();
        	}
        }
        return re;
    }
}

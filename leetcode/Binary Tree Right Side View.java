/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> view = new ArrayList<Integer>();
        if (root == null) {
            return view;
        }
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.add(root);
        int current = 1;
        int next = 0;
        while (queue.size() > 0) {
            TreeNode cur = queue.poll();
            --current;
            if (cur.left != null) {
                queue.add(cur.left);
                ++next;
            }
            if (cur.right != null) {
                queue.add(cur.right);
                ++next;
            }
            if (current == 0) {
                view.add(cur.val);
                current = next;
                next = 0;
            }
        }
        return view;
    }
}

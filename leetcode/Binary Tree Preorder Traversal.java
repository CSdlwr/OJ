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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> re = new ArrayList<Integer>();
        Stack<TreeNode> st = new Stack<TreeNode>();
        if (root != null) st.push(root);
        TreeNode t = null;
        while (!st.empty()) {
        	t = st.pop(); re.add(t.val);
        	if (t.right != null) st.push(t.right);
        	if (t.left != null) st.push(t.left);
        }
        return re;
    }
}

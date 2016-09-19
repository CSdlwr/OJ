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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> re = new ArrayList<Integer>();
        Stack<TreeNode> st = new Stack<TreeNode>();
        if (root == null) return re;
        TreeNode cur = root;
        while (!st.empty() || cur != null) {
        	if (cur != null) {
        		st.push(cur); cur = cur.left;
        	}
        	else {
        		cur = st.pop();
        		re.add(cur.val);
        		cur = cur.right;
        	}
        }
        return re;
    }
}

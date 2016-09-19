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
    public TreeNode sortedArrayToBST(int[] num) {
        TreeNode root = null;
        if (num == null || num.length == 0) return root;
        root = solve(num, 0, num.length);
        return root;
    }
    
    public TreeNode solve(int num[], int x, int y) {
    	TreeNode root = null;
    	if (x >= y) return root;
    	int m = x + (y-x)/2, v = num[m];
    	root = new TreeNode(v);
    	root.left = solve(num, x, m);
    	root.right = solve(num, m+1, y);
    	return root;
    }
}

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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> pathString = new ArrayList<String>();
        if (root == null) {
            return pathString;
        }
        int[] path = new int[1000];
        traverse(root, path, 0, pathString);
        return pathString;
    }

    private void traverse(TreeNode root, int[] path, int depth, List<String> pathString) {
        path[depth] = root.val;
        if (root.left == null && root.right == null) {
            pathString.add(generatePath(path, depth));
            return;
        }
        if (root.left != null) {
            traverse(root.left, path, depth + 1, pathString);
        }

        if (root.right != null) {
            traverse(root.right, path, depth + 1, pathString);
        }
    }

    private String generatePath(int[] path, int depth) {
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i <= depth; ++i) {
            builder.append(path[i]).append("->");
        }
        return builder.substring(0, builder.length() - 2);
    }
}


public class PathSumIII {

    class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) {
	    val = x;
	}
    }

    private int ans;
    private int sum;

    public int pathSum(TreeNode root, int sum) {
	if (root == null) {
	    return 0;
	}

	this.sum = sum;
	this.ans = 0;
	traverse(root, sum, true);

	return ans;
    }

    private void traverse(TreeNode root, int target, boolean isBeginning) {
	if (root == null) {
	    return;
	}

	if (root.val == target) {
	    ++ans;
	}
	if (root.left != null) {
	    traverse(root.left, target - root.val, false);
	    if (isBeginning) {
		traverse(root.left, sum, true);
	    }
	}
	
	if (root.right != null) {
	    traverse(root.right, target - root.val, false);
	    if (isBeginning) {
		traverse(root.right, sum, true);
	    }
	}
    }
}

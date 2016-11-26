import java.util.HashMap;
import java.util.Map;

public class HouseRobberIII {

    class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) {
	    val = x;
	}
    }

    Map<TreeNode, Integer> notChooseRootCache = new HashMap<TreeNode, Integer>();
    Map<TreeNode, Integer> chooseRootCache = new HashMap<TreeNode, Integer>();

    public int rob(TreeNode root) {
	return Math.max(traverse(root, false), traverse(root, true));
    }

    private int traverse(TreeNode root, boolean chooseRoot) {
	int sum = 0;
	if (root == null) {
	    return sum;
	}
	if (chooseRoot) {
	    Integer cache = chooseRootCache.get(root);
	    if (cache != null) {
		return cache;
	    }
	    sum += root.val;
	    sum += traverse(root.left, false);
	    sum += traverse(root.right, false);
	    chooseRootCache.put(root, sum);
	} else {
	    Integer cache = notChooseRootCache.get(root);
	    if (cache != null) {
		return cache;
	    }
	    sum += Math.max(traverse(root.left, false), traverse(root.left, true)); 
	    sum += Math.max(traverse(root.right, false), traverse(root.right, true)); 
	    notChooseRootCache.put(root , sum);
	}
	return sum;
    }
    
}

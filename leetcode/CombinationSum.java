import java.util.List;
import java.util.ArrayList;

public class CombinationSum {

    private List<List<Integer>> ans;
    private int[] choose;

    public static void main(String[] args) {
	CombinationSum main = new CombinationSum();
	System.out.println(main.combinationSum(new int[] {2, 3, 6, 7}, 7));
    }
    
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
	ans = new ArrayList<List<Integer>>();
	if (candidates == null || candidates.length == 0 || target <= 0) {
	    return ans;
	}

	choose = new int[candidates.length];
	helper(candidates, 0, target);
	return ans;
    }

    private void helper(int[] candidates, int currIndex, int targetRemaining) {
	if (targetRemaining == 0) {
	    List<Integer> t = new ArrayList<Integer>();
	    for (int i = 0; i < candidates.length; ++i) {
		for (int j = 0; j < choose[i]; ++j) {
		    t.add(candidates[i]);
		}
	    }
	    ans.add(t);
	    return;
	}
	
	if (currIndex >= candidates.length || targetRemaining < 0) {
	    return;
	}
	choose[currIndex] += 1;
	helper(candidates, currIndex, targetRemaining - candidates[currIndex]);
	//helper(candidates, currIndex + 1, targetRemaining - candidates[currIndex]);
	choose[currIndex] -= 1;
	helper(candidates, currIndex + 1, targetRemaining);
    }
}

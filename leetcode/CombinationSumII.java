import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.ArrayList;
import java.util.List;

public class CombinationSumII {

    private List<List<Integer>> ans;
    private boolean[] choose;

    public static void main(String[] args) {
	CombinationSumII main = new CombinationSumII();
	System.out.println(main.combinationSum2(new int[] {14,6,25,9,30,20,33,34,28,30,16,12,31,9,9,12,34,16,25,32,8,7,30,12,33,20,21,29,24,17,27,34,11,17,30,6,32,21,27,17,16,8,24,12,12,28,11,33,10,32,22,13,34,18,12}, 27));
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
	ans = new ArrayList<List<Integer>>();
	if (candidates == null || candidates.length == 0 || target <= 0) {
	    return ans;
	}
	choose = new boolean[candidates.length];
	Arrays.sort(candidates);
	helper(candidates, 0, target);
	return ans;
    }

    private void helper(int[] candidates, int currIndex, int targetRemaining) {
	if (targetRemaining == 0) {
	    List<Integer> t = new ArrayList<Integer>();
	    for (int i = 0; i < candidates.length; ++i) {
		if (choose[i]) {
		    t.add(candidates[i]);
		}
	    }
	    ans.add(t);
	    return;
	}
	//while (currIndex < candidates.length - 1 && candidates[currIndex] == candidates[currIndex + 1]) {
	//++currIndex;
	//}
	if (currIndex >= candidates.length || targetRemaining < 0) {
	    return;
	}
	if (currIndex > 0 && candidates[currIndex - 1] == candidates[currIndex] && !choose[currIndex - 1]) {
	    helper(candidates, currIndex + 1, targetRemaining);
	} else {
	    choose[currIndex] = true;
	    helper(candidates, currIndex + 1, targetRemaining - candidates[currIndex]);
	    choose[currIndex] = false;
	    helper(candidates, currIndex + 1, targetRemaining);
	}
    }
}

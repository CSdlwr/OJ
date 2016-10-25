import java.util.ArrayList;
import java.util.List;

public class CombinationSumIII {

    private List<List<Integer>> ans;
    private int[] candidates;
    private boolean[] choose;

    public static void main(String[] args) {
	CombinationSumIII main = new CombinationSumIII();
	System.out.println(main.combinationSum3(3, 15));
    }

    public List<List<Integer>> combinationSum3(int k, int n) {
	ans = new ArrayList<List<Integer>>();
	if (n <= 0 || k <= 0) {
	    return ans;
	}
	candidates = new int[9];
	choose = new boolean[9];
	for (int i = 0; i < candidates.length; ++i) {
	    candidates[i] = i + 1;
	}
	helper(0, n, k);
	return ans;
    }
    
    private void helper(int currIndex, int nRemaining, int kRemaining) {
	if (nRemaining == 0 && kRemaining == 0) {
	    List<Integer> t = new ArrayList<Integer>();
	    for (int i = 0; i < choose.length; ++i) {
		if (choose[i]) {
		    t.add(candidates[i]);
		}
	    }
	    ans.add(t);
	    return;
	}
	if (currIndex >= candidates.length) {
	    return;
	}
	choose[currIndex] = true;
	helper(currIndex + 1, nRemaining - candidates[currIndex], kRemaining - 1);
	choose[currIndex] = false;
	helper(currIndex + 1, nRemaining, kRemaining);
    }
}

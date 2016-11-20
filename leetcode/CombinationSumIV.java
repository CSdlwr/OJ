
public class CombinationSumIV {

    private int ans;

    public static void main(String[] args) {
	CombinationSumIV main = new CombinationSumIV();
	System.out.println(main.combinationSum4(new int[] {1, 2, 3}, 7));
    }

    public int combinationSum4(int[] nums, int target) {
	if (nums == null || nums.length == 0 || target <= 0) {
	    return 0;
	}

	int d[] = new int[target + 1];
	d[0] = 1;
	for (int i = 1; i <= target; ++i) {
	    for (int j = 0; j < nums.length; ++j) {
		if (nums[j] <= i) {
		    d[i] += d[i - nums[j]];
		}
	    }
	}
	return d[target];
    }

    public int combinationSum4_1(int[] nums, int target) {
	if (nums == null || nums.length == 0 || target <= 0) {
	    return 0;
	}
	ans = 0;
	helper(nums, 0, target);
	return ans;
    }

    private void helper(int[] nums, int currIndex, int targetRemaining) {
	if (targetRemaining == 0) {
	    ++ans;
	    return;
	}
	if (currIndex >= nums.length || targetRemaining < 0) {
	    return;
	}
	helper(nums, 0, targetRemaining - nums[currIndex]);
	helper(nums, currIndex + 1, targetRemaining);
    }
}

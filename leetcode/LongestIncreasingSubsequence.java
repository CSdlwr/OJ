
public class LongestIncreasingSubsequence {

    private int ans;

    public static void main(String[] args) {
	LongestIncreasingSubsequence main = new LongestIncreasingSubsequence();
	System.out.println(main.lengthOfLIS(new int[] {10, 9, 2, 5, 3, 7, 101, 18}));
    }

    public int lengthOfLIS(int[] nums) {
	if (nums == null || nums.length == 0) {
	    return 0;
	}
	ans = 0;
	int[] d = new int[nums.length];
	for (int i = 0; i < d.length; ++i) {
	    d[i] = 1;
	}

	for (int i = 1; i < nums.length; ++i) {
	    for (int j = 0; j < i; ++j) {
		if (nums[j] < nums[i] && d[j] + 1 > d[i]) {
		    d[i] = d[j] + 1;
		    if (d[i] > ans) {
			ans = d[i];
		    }
		}
	    }
	}
	return ans == 0 ? 1 : ans;
    }
}

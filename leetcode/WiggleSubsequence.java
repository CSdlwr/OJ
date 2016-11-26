
public class WiggleSubsequence {

    public int wiggleMaxLength(int[] nums) {
	if (nums == null || nums.length == 0) {
	    return 0;
	}
	int[] d = new int[nums.length];
	int[] resultBy = new int[nums.length];
	d[0] = 1;
	resultBy[0] = 0;
	for (int i = 1; i < nums.length; ++i) {
	    int t = 0;
	    for (int j = 0; j < i; ++j) {
		if (nums[j] < nums[i] && resultBy[j] <= 0 ) {
		    t = d[j] + 1;
		    if (t > d[i]) {
			d[i] = t;
			resultBy[i] = 1;
		    }
		} else if (nums[j] > nums[i] && resultBy[j] >= 0) {
		    t = d[j] + 1;
		    if (t > d[i]) {
			d[i] = t;
			resultBy[i] = -1;
		    }
		}
	    }
	}
	int m = 0;
	for (int i : d) {
	    if (i > m) {
		m = i;
	    }
	}
	return m;
    }
}

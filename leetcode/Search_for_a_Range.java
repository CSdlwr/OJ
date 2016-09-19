public class Solution {
	public int[] searchRange(int A[], int target) {
		int[] rtn = new int[2];
		rtn[0] = lower(A, 0, A.length, target);
		if (rtn[0] == -1) rtn[1] = -1;
		else {
			rtn[1] = upper(A, 0, A.length, target);
			--rtn[1];
		}
		return rtn;
	}

	public int lower(int A[], int x, int y, int t) {
		int m = 0;
		while (x < y) {
			m = x + (y-x)/2;
			if (A[m] >= t) y = m;
			else x = m+1;
		}
		if (x >= A.length) return -1;
		return A[x] == t ? x : -1;
	}
	
	public int upper(int A[], int x, int y, int t) {
		int m = 0;
		while (x < y) {
			m = x + (y-x)/2;
			if (A[m] <= t) x = m+1;
			else y = m;
		}
		return x;
	}
}

public class Solution {
    public int search(int[] A, int target) {
	int x = 0, y = A.length;
	int m = 0;
	while (x < y) {
		m = x + (y-x)/2;
		if (A[m] == target)
			return m;
		else if (A[m] > target) {
			if (A[m] > A[x]) {
				if (target >= A[x])
					y = m;
				else x = m+1;
			} else {
				y = m;
			}
		} else {
			if (A[m] < A[x]) {
				if (target <= A[y-1]) 
					x = m+1;
				else y = m;
			} else {
				x = m+1;
			}
		}
	}
	return -1;
    }
}

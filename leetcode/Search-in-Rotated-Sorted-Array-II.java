public class Solution {
	public boolean search(int A[], int target) {
		int x = 0, y = A.length;
		int m = 0;
		while (x < y) {
			m = x + (y-x)/2;
			if (A[m] == target)
				return true;
			else if (A[m] > target) {
				if (A[x] < A[m]) {
					if (target >= A[x])
						y = m;
					else x = m+1;
				} else if (A[x] > A[m])
					y = m;
				else ++x;
			} else {
				if (A[m] < A[y-1]) {
					if (target <= A[y-1])
						x = m+1;
					else y = m;
				} else if (A[m] > A[y-1])
					x = m+1;
				else --y;
			}
		}
		return false;
	}
}

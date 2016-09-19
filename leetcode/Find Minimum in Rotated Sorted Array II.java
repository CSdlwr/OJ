public class Solution {
	public int getMin(int a, int b) {
		return a < b ? a : b;
	}
	
	public int findMin(int[] num) {
		int x = 0, y = num.length;
		int mm = Integer.MAX_VALUE;
		int m = 0;
		while (x < y) {
			m = x + (y-x)/2;
			mm = getMin(num[m], mm);
			if (num[m] < num[y-1]) {
				mm = getMin(mm, num[m]);
				y = m;
			} else if (num[m] > num[x]) {
				mm = getMin(mm, num[x]);
				x = m+1;
			} else ++x;
		}
		return mm;
	}
}

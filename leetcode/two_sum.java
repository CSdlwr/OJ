public class Solution {
	public void mergeSort(int a[], int x, int y, int t[]) {
		if (y-x <= 1) return ;
		int m = x + (y-x)/2;
		mergeSort(a, x, m, t);
		mergeSort(a, m, y, t);
		int p = x, q = m;
		int i = x;
		while (p < m || q < y) {
			if (q >= y || (p < m && a[p] < a[q])) t[i++] = a[p++];
			else t[i++] = a[q++];
		}
		for (i = x; i < y; ++i) a[i] = t[i];
	}
	
	public int[] twoSum(int[] numbers, int targets) {
		int[] nm = new int[numbers.length];
		System.arraycopy(numbers, 0, nm, 0, nm.length);
		int rtn[] = new int[2];
		int t[] = new int[numbers.length];
		mergeSort(numbers, 0, numbers.length, t);
		int i = 0, j = numbers.length-1;
		while (i <= j) {
			if (numbers[i] + numbers[j] == targets) {
				rtn[0] = numbers[i];
				rtn[1] = numbers[j];
				break;
			} 
			else if (numbers[i]+numbers[j] < targets)
				++i;
			else --j;
		}
		i = 0;
		while (nm[i] != rtn[0]) ++i;
		rtn[0] = i+1;
		i = nm.length-1;
		while (nm[i] != rtn[1]) --i;
		rtn[1] = i+1;
		if (rtn[0] > rtn[1]) {
			i = rtn[0]; rtn[0] = rtn[1]; rtn[1] = i;
		}
		return rtn;
	}
}

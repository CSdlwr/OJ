public class Solution {
    public void nextPermutation(int[] num) {
	int len = num.length;
	int x = -1, y = len-2;
	int t = 0;
	while (y >= 0 && num[y] >= num[y+1]) {
		--y;
	}
	if (y < 0) {
		int i = 0, j = len-1;
		while (i < j) {
			t = num[i];
			num[i] = num[j];
			num[j] = t;
			++i;
			--j;
		}
	} else {
		t = num[y];
		Arrays.sort(num, y, len);
		for (int i = y; i < len; ++i) {
			if (num[i] > t) {
				t = num[i];
				for (int j = i-1; j >= y; --j)
					num[j+1] = num[j];
				num[y] = t;
				break;
			}
		}
	}
    }
}

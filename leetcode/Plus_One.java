public class Solution {
    public int[] plusOne(int[] digits) {
		int i = 0, j = digits.length-1;
		int t = 0;
		while (i < j) { 
			t = digits[i]; digits[i] = digits[j]; digits[j] = t;
			++i; --j;
		}
		int ca = 1;
		for (i = 0; i < digits.length; ++i) {
			digits[i] += ca;
			ca = digits[i] / 10;
			digits[i] %= 10;
		}
		if (ca > 0) {
			int nd[] = new int[digits.length+1];
			for (i = 0; i < digits.length; ++i) nd[i] = digits[i];
			nd[i] = 1;
			digits = nd;
		}
		i = 0; j = digits.length-1;
		while (i < j) {
			t = digits[i]; digits[i] = digits[j]; digits[j] = t;
			++i; --j;
		}
		return digits;  
    }
}

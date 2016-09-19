public class Solution {
	public int romanToInt(String s) {
		if (s == null || s.length() == 0) return 0;
		int sum = revert(s.charAt(0));
		int p = revert(s.charAt(0));
		int q = 0;
		for (int i = 1; i < s.length(); ++i) {
			q = revert(s.charAt(i));
			if (q <= p) sum += q;
			else sum = sum - p * 2 + q;
			p = q;
		}
		return sum;
	}
	
	public int revert(char x) {
		int v = 0;
		switch(x) {
		case 'I': { v = 1; break; }
		case 'V': { v = 5; break; }
		case 'X': { v = 10; break; }
		case 'L': { v = 50; break; }
		case 'C': { v = 100; break; }
		case 'D': { v = 500; break; }
		case 'M': { v = 1000; break; }
		default : break;
		}
		return v;
	}
}

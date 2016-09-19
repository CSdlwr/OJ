public class Solution {
	public int atoi(String str) {
		Long ans = 0l;
		int i = 0, l = str.length();
		boolean neg = false;
		while (i < l && str.charAt(i) == ' ') {
			++i;
		}
		if (i < l && (str.charAt(i) > '9' || str.charAt(i) < '0')) {
			if (str.charAt(i) == '-')
				neg = true;
			else if (str.charAt(i) != '+')
				return 0;
			++i;
		}
		int j = i;
		for (; i < l; ++i) {
			if (str.charAt(i) > '9' || str.charAt(i) < '0')
				break;
			ans = ans * 10 + str.charAt(i) - '0';
		}
		if (i-j > 10) {
			if (!neg) 
				return Integer.MAX_VALUE;
			return Integer.MIN_VALUE;
		}
		if (!neg && ans > Integer.MAX_VALUE)
			return Integer.MAX_VALUE;
		if (neg && ans > ((long) Integer.MAX_VALUE)+1)
			return Integer.MIN_VALUE;
		if (neg)
			ans *= -1;
		return ans.intValue();
	}
}

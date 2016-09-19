public class Solution {
	public int numDistinct(String S, String T) {
		int ls = S.length();
		int lt = T.length();
		int d[][] = new int[++lt][++ls];
		for (int i = 0; i < ls; ++i)
			d[0][i] = 1;
		for (int i = 1; i < lt; ++i) {
			for (int j = 1; j < ls; ++j) {
				d[i][j] = d[i][j-1];
				if (T.charAt(i-1) == S.charAt(j-1))
					d[i][j] += d[i-1][j-1];
			}
		}
		return d[lt-1][ls-1];
	}
}

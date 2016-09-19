public class Solution {
	int getMin(int x, int y) {
		return x > y ? y : x;
	}

	public int minDistance(String word1, String word2) {
		int l1 = word1.length();
		int l2 = word2.length();
		int d[][] = new int[++l1][++l2];
		for (int i = 0; i < l1; ++i)
			d[i][0] = i;
		for (int i = 0; i < l2; ++i)
			d[0][i] = i;
		for (int i = 1; i < l1; ++i) {
			for (int j = 1; j < l2; ++j) {
				if (word1.charAt(i-1) == word2.charAt(j-1))
					d[i][j] = d[i-1][j-1];
				else {
					d[i][j] = getMin(d[i-1][j], getMin(d[i-1][j-1], d[i][j-1]));
					++d[i][j];
				}
			}
		}
		return d[l1-1][l2-1];
	}
}

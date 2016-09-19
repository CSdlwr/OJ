public class Solution {
	public void rotate1(int[][] matrix, int n) {
		int t = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				t = matrix[i][j]; 
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = t;
			}
		}
	}
	
	public void revert(int[] A) {
		int i = 0, j = A.length-1, t = 0;
		while (i < j) {
			t = A[i]; A[i] = A[j]; A[j] = t;
			++i; --j;
		}
	}

	public void rotate(int[][] matrix) {
		int n = matrix.length;
		rotate1(matrix, n);
		for (int i = 0; i < n; ++i) 
			revert(matrix[i]);
	}
}

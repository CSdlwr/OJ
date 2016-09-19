public class Solution {
    public void setZeroes(int[][] matrix) {
		int m = matrix.length;
		int n = matrix[0].length;
		
		boolean a = false, b = false;
		for (int j = 0; j < n; ++j) 
			if (matrix[0][j] == 0) {
				a = true; break;
			}
		
		for (int i = 0; i < m; ++i)
			if (matrix[i][0] == 0) {
				b = true; break;
			}
		
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == 0) {
					matrix[0][j] = matrix[i][0] = 0;
				}
			}
		}
		
		for (int j = 1; j < n; ++j) {
			if (matrix[0][j] == 0) {
				for (int i = 0; i < m; ++i) matrix[i][j] = 0;
			}
		}
		
		for (int i = 1; i < m; ++i) {
			if (matrix[i][0] == 0) {
				for (int j = 0; j < n; ++j) matrix[i][j] = 0;
			}
		}
		
		if (a) for (int j = 0; j < n; ++j) matrix[0][j] = 0;
		if (b) for (int i = 0; i < m; ++i) matrix[i][0] = 0;
    }
}

public class Solution {
	boolean vs[] = new boolean[10];
	
	char[][] g;

	public boolean isValidSudoku(char[][] board) {
		g = board;
		for (int i = 0; i < 9; ++i)
			if (!judgeRow(i) || !judgeCol(i)) 
				return false;
		for (int i = 0; i < 9; i += 3)
			for (int j = 0; j < 9; j += 3)
				if (!judgeBox(i, j)) return false;
		return true;
	}
	
	public boolean judgeBox(int x, int y) {
		for (int i = 0; i < 10; ++i) vs[i] = false;
		for (int i = x; i < x+3; ++i) {
			for (int j = y; j < y+3; ++j) {
				if (g[i][j] != '.' && vs[g[i][j]-'0'])
					return false;
				else if (g[i][j] != '.') 
					vs[g[i][j]-'0'] = true;
			}
		}
		return true;
	}
	
	public boolean judgeCol(int c) {
		for (int i = 0; i < 10; ++i) vs[i] = false;
		for (int i = 0; i < 9; ++i) {
			if (g[i][c] != '.' && vs[g[i][c]-'0'])
				return false;
			else if (g[i][c] != '.') 
				vs[g[i][c]-'0'] = true;
		}
		return true;
	}
	
	public boolean judgeRow(int r) {
		for (int i = 0; i < 10; ++i) vs[i] = false;
		for (int i = 0; i < 9; ++i) {
			if (g[r][i] != '.' && vs[g[r][i]-'0'])
				return false;
			else if (g[r][i] != '.') 
				vs[g[r][i]-'0'] = true;
		}
		return true;
	}
}

public class Solution {
	boolean fd = false;
	char[][] g;
	boolean[][] vs;
	int m, n;
	char[] w;
	
	public void solve(char[] w, int x, int y, int dep) {
		if (dep == w.length) { fd = true; return ; }
		if (x >= m || y >= n || x < 0 || y < 0) return ;
		if (w[dep] != g[x][y] || vs[x][y]) return ;
		vs[x][y] = true;
		solve(w, x-1, y, dep+1);
		if (fd) return ;
		solve(w, x+1, y, dep+1);
		if (fd) return ;
		solve(w, x, y-1, dep+1);
		if (fd) return ;
		solve(w, x, y+1, dep+1);
		if (fd) return ;
		vs[x][y] = false;
	}
	
	public boolean exist(char[][] board, String word) {
		if (board == null || board.length == 0
			|| word == null || word.length() == 0) return false;
		fd = false; g = board;
		m = g.length; n = g[0].length;
		vs = new boolean[m][n];
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				vs[i][j] = false;
		w = word.toCharArray();
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if(g[i][j] == w[0]) solve(w, i, j, 0);
				if (fd) return true;
			}
		}
		return false;
	}
}

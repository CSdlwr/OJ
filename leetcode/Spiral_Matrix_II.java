public class Solution {
    
	int g[][];
	int cnt;
    
	public int[][] generateMatrix(int n) {
		g = new int[n][n]; cnt = 0;
		solve(0, n-1, 0, n-1);
		return g;
	}
	
	public void solve(int sx, int ex, int sy, int ey) {
		if (sx > ex || sy > ey) return ;
		for (int i = sy; i <= ey; ++i) g[sx][i] = ++cnt;
		for (int i = sx+1; i <= ex; ++i) g[i][ey] = ++cnt;
		for (int i = ey-1; i >= sy; --i) g[ex][i] = ++cnt;
		for (int i = ex-1; i > sx; --i) g[i][sy] = ++cnt;
		solve(sx+1, ex-1, sy+1, ey-1);
	}
}

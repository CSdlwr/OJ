public class Solution {
	int[][] d;
	int[][] g;
	int m, n;
	
	public int solve(int x, int y) {
		if (x > m || y > n) return 0;
		if (g[x][y] == 1) return d[x][y] = 0;
		if (x == m && y == n) return d[x][y] = 1;
		if (d[x][y] != -1) return d[x][y];
		++d[x][y];
		d[x][y] += solve(x+1, y);
		d[x][y] += solve(x, y+1);
		return d[x][y];
	}
	
	public int uniquePathsWithObstacles(int[][] obstacleGrid) {
		m = obstacleGrid.length; 
		n = obstacleGrid[0].length;
		d = new int[m][n]; 
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				d[i][j] = -1;
		--m; --n;
		g = obstacleGrid;
		solve(0, 0);
		return d[0][0];
	}
}

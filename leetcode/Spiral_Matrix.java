public class Solution {
	List<Integer> ans;
	int[][] g;
	
	public List<Integer> spiralOrder(int[][] matrix) {
		ans = new ArrayList<Integer>();
		g = matrix;
		if (matrix == null) return ans;
		int m = matrix.length;
		if (m == 0) return ans;
		int n = matrix[0].length;
		if (n == 0) return ans;
		solve(0, m-1, 0, n-1);
		return ans;
	}
	
	public void solve(int sx, int ex, int sy, int ey) {
		if (sx > ex || sy > ey) return ;
		for (int i = sy; i <= ey; ++i) ans.add(g[sx][i]);
		for (int i = sx+1; i <= ex; ++i) ans.add(g[i][ey]);
		if (sx != ex) for (int i = ey-1; i >= sy; --i) ans.add(g[ex][i]);
		if (sy != ey) for (int i = ex-1; i > sx; --i) ans.add(g[i][sy]);
		solve(sx+1, ex-1, sy+1, ey-1);
	}
}

public class Solution {
	int m, n;
	int dt[][] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	
	public void solve(char[][] board) {
		if (board == null || board.length == 0) 
			return ;
		m = board.length;
		n = board[0].length;
		if (m < 2 || n < 2) return ;
		for (int j = 0; j < n; ++j) { 
			if (board[0][j] == 'O') 
				bfs(board, 0, j);
			if (board[m-1][j] == 'O')
				bfs(board, m-1, j);
		}
		for (int i = 0; i < m; ++i) {
			if (board[i][0] == 'O')
				bfs(board, i, 0);
			if (board[i][n-1] == 'O')
				bfs(board, i, n-1);
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				else if (board[i][j] == '.')
					board[i][j] = 'O';
			}
		}
	}
	
	public void bfs(char[][] g, int x, int y) {
		g[x][y] = '.';
		Queue<Integer> que = new LinkedList<Integer>();
		que.add(x*n+y);
		int nx = 0, ny = 0;
		int cur = 0;
		while (que.size() > 0) {
			cur = que.poll();
			x = cur / n;
			y = cur % n;
			for (int i = 0; i < dt.length; ++i) {
				nx = x + dt[i][0];
				ny = y + dt[i][1];
				if (nx >= 0 && nx < m 
						&& ny >= 0 && ny < n 
						&& g[nx][ny] == 'O') {
					g[nx][ny] = '.';
					que.add(nx*n+ny);
				}
			}
		}
	}
}

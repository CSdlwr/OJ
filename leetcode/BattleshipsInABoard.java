
public class BattleshipsInABoard {
    
    public int countBattleships(char[][] board) {
	if (board == null || board.length == 0) {
	    return 0;
	}
	char[][] visited = new char[board.length][board[0].length];
	int ans = 0;
	for (int i = 0; i < board.length; ++i) {
	    for (int j = 0; j < board[i].length; ++j) {
		if (board[i][j] == 'X' && visited[i][j] != 1) {
		    ++ans;
		    finder(board, visited, i, j);
		}
	    }
	}
	return ans;
    } 

    private void finder(char[][] board, char[][] visited, int i, int j) {
	if (i < 0 || j < 0 || i >= board.length || j >= board[0].length || board[i][j] != 'X' || visited[i][j] == 1) {
	    return;
	} 
	visited[i][j] = 1;
	finder(board, visited, i - 1, j);
	finder(board, visited, i + 1, j);
	finder(board, visited, i, j - 1);
	finder(board, visited, i, j + 1);
    }
}

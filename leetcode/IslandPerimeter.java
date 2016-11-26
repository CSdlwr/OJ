
public class IslandPerimeter {

    public static void main(String[] args) {
	IslandPerimeter main = new IslandPerimeter();
	System.out.printf("%d\n", main.IslandPerimeter(new int[][] {}));
    }

    public int islandPerimeter(int[][] grid) {
        
	int ans = 0;
	if (grid == null || grid.length == 0) {
	    return ans;
	}
	int rows = grid.length;
	int cols = grid[0].length;
	for (int i = 0; i < rows; ++i) {
	    for (int j = 0; j < cols; ++j) {
		if (grid[i][j] == 1) {
		    if (i == 0 || grid[i - 1][j] == 0) {
			++ans;
		    }
		    if (i == rows - 1 || grid[i + 1][j] == 0) {
			++ans;
		    }
		    if (j == 0 || grid[i][j - 1] == 0) {
			++ans;
		    }
		    if (j == cols - 1 || grid[i][j + 1] == 0) {
			++ans;
		    }
		}
	    }
	}
	return ans;
    }
}

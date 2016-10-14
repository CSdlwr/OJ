public class Solution {
    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }
        char[][] visit = new char[grid.length][grid[0].length];
        
        int ans = 0;
        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[i].length; ++j) {
                if (visit[i][j] == 0 && grid[i][j] != '0') {
                    ++ans;
                    traverse(grid, visit, i, j);
                }
            }
        }
        return ans;
    }

    private void traverse(char[][] grid, char[][] visit, int i, int j) {
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] == '0' || visit[i][j] != 0) {
            return;
        }
        visit[i][j] = 1;
        traverse(grid, visit, i - 1, j);
        traverse(grid, visit, i + 1, j);
        traverse(grid, visit, i, j - 1);
        traverse(grid, visit, i, j + 1);
    }
}

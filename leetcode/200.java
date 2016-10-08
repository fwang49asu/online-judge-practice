public class Solution {
    public int numIslands(char[][] grid) {
        int result = 0;
        int n = grid.length;
        if(n == 0) {
            return 0;
        }
        int m = grid[0].length;
        for(int i=0; i<n; ++i) {
            for(int k=0; k<m; ++k) {
                if(grid[i][k] == '1') {
                    ++result;
                    flood(grid, i, k);
                }
            }
        }
        return result;
    }
    private void flood(char[][] grid, int y, int x) {
        int n = grid.length;
        int m = grid[0].length;
        if(y < 0 || y >= n || x < 0 || x >= m || grid[y][x] != '1') {
            return;
        }
        grid[y][x] = '2';
        flood(grid, y-1, x);
        flood(grid, y+1, x);
        flood(grid, y, x-1);
        flood(grid, y, x+1);
    }
}

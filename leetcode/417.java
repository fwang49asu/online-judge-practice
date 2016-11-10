public class Solution {
    public List<int[]> pacificAtlantic(int[][] matrix) {
        List<int[]> result = new ArrayList<>();
        if(matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return result;
        }
        int n = matrix.length;
        int m = matrix[0].length;
        boolean pacific[][] = new boolean[n][m];
        boolean atlantic[][] = new boolean[n][m];
        for(int i=0; i<n; ++i) {
            flood(i, 0, matrix, pacific);
        }
        for(int i=0; i<m; ++i) {
            flood(0, i, matrix, pacific);
        }
        for(int i=0; i<n; ++i) {
            flood(i, m-1, matrix, atlantic);
        }
        for(int i=0; i<m; ++i) {
            flood(n-1, i, matrix, atlantic);
        }
        for(int i=0; i<n; ++i) {
            for(int k=0; k<m; ++k) {
                if(pacific[i][k] && atlantic[i][k]) {
                    result.add(new int[]{i, k});
                }
            }
        }
        return result;
    }
    private void flood(int y, int x, int[][] matrix, boolean[][] visited) {
        if(visited[y][x]) {
            return;
        }
        visited[y][x] = true;
        int offset[] = {-1, 0, 1, 0, -1};
        int n = matrix.length;
        int m = matrix[0].length;
        for(int i=0; i<4; ++i) {
            int yn = offset[i] + y;
            int xn = offset[i+1] + x;
            if(yn >= 0 && yn < n && xn >= 0 && xn < m && !visited[yn][xn] && matrix[y][x] <= matrix[yn][xn]) {
                flood(yn, xn, matrix, visited);
            }
        }
    }
}

public class NumMatrix {
    private int[][] matrix;
    public NumMatrix(int[][] matrix) {
        int n = matrix.length;
        if(n == 0) {
            return;
        }
        int m = matrix[0].length;
        for(int i=1; i<m; ++i) {
            matrix[0][i] += matrix[0][i-1];
        }
        for(int i=1; i<n; ++i) {
            matrix[i][0] += matrix[i-1][0];
            for(int k=1; k<m; ++k) {
                matrix[i][k] += matrix[i][k-1] + matrix[i-1][k] - matrix[i-1][k-1];
            }
        }
        this.matrix = matrix;
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        int result = matrix[row2][col2];
        if(row1 != 0) {
            result -= matrix[row1-1][col2];
        }
        if(col1 != 0) {
            result -= matrix[row2][col1-1];
        }
        if(row1 != 0 && col1 != 0) {
            result += matrix[row1-1][col1-1];
        }
        return result;
    }
}


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix = new NumMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

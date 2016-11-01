public class NumMatrix {

    public NumMatrix(int[][] matrix) {
        data = matrix;
        int n = matrix.length;
        if(n == 0) {
            return;
        }
        int m = matrix[0].length;
        helper = new int[n][m+1];
        for(int row = 0; row < n; ++row) {
            for(int i=1; i<=m; ++i) {
                helper[row][i] = data[row][i-1];
                int lower = i - lowbit(i);
                for(int k=i-1; k>lower; --k) {
                    helper[row][i] += data[row][k-1];
                }
            }
        }
    }

    public void update(int row, int col, int val) {
        int delta = val - data[row][col];
        data[row][col] = val;
        for(++col; col <= data[row].length; col += lowbit(col)) {
            helper[row][col] += delta;
        }
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        if(data.length == 0 || data[0].length == 0) {
            return 0;
        }
        int result = 0;
        for(int i=row1; i<=row2; ++i) {
            result += rowPrefixSum(i, col2 + 1) - rowPrefixSum(i, col1);
        }
        return result;
    }

    public int rowPrefixSum(int row, int col) {
        int result = 0;
        for(; col > 0; col &= ~lowbit(col)) {
            result += helper[row][col];
        }
        return result;
    }

    int data[][];
    int helper[][];

    private int lowbit(int x) {
        return x & (-x);
    }
}


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix = new NumMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);

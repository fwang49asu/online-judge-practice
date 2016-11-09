public class TicTacToe {

    /** Initialize your data structure here. */
    public TicTacToe(int n) {
        rowCount = new int[n];
        colCount = new int[n];
        diagnalCount = new int[2];
        this.n = n;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    public int move(int row, int col, int player) {
        int diff = player == 1 ? -1 : 1;
        rowCount[row] += diff;
        colCount[col] += diff;
        if(row == col) {
            diagnalCount[0] += diff;
        }
        if((row + col) == n-1) {
            diagnalCount[1] += diff;
        }
        if(rowCount[row] == n) {
            return 2;
        }
        if(rowCount[row] == -n) {
            return 1;
        }
        if(colCount[col] == n) {
            return 2;
        }
        if(colCount[col] == -n) {
            return 1;
        }
        if(diagnalCount[0] == n) {
            return 2;
        }
        if(diagnalCount[0] == -n) {
            return 1;
        }
        if(diagnalCount[1] == n) {
            return 2;
        }
        if(diagnalCount[1] == -n) {
            return 1;
        }
        return 0;
    }

    private int rowCount[];
    private int colCount[];
    private int diagnalCount[];
    private int n;
}

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */

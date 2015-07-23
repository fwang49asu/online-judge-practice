class Solution {
public:
    bool isValid(vector<vector<char>> &board, int irow, int icol) {
        char val = board[irow][icol];
        if(val-'0'<1 || val-'0'>9) return false;
        
        // check row & col
        for(int i=0; i<9; i++) {
            if(board[irow][i]==val && i!=icol) return false;
            if(board[i][icol]==val && i!=irow) return false;
        }
        
        //check 3x3 box
        int irow0 = irow/3*3;
        int icol0 = icol/3*3;
        for(int i=irow0; i<irow0+3; i++) {
            for(int j=icol0; j<icol0+3; j++) {
                if(board[i][j]==val && (i!=irow || j!=icol)) return false;
            }
        }
        
        return true;
    }
    bool solver(vector<vector<char>> &board,int row, int col){
        if(row==9)
            return true;
        int newrow,newcol;
        if(col==8){
            newrow=row+1;
            newcol=0;
        }
        else{
            newrow=row;
            newcol=col+1;
        }
        if(board[row][col]!='.'){
            if(!isValid(board,row,col))
                return false;
            return solver(board,newrow,newcol);
        }
        
        for(char k='1';k<='9';k++){
            board[row][col]=k;
            if(isValid(board,row,col)&&solver(board,newrow,newcol))
                return true;
        }
        
        board[row][col]='.';
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solver(board,0,0);
    }
};
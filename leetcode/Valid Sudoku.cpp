class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int row=i/3,col=j/3;
                    for(int k=0;k<9;k++){
                        if(k!=i&&board[i][j]==board[k][j])
                            return false;
                        if(k!=j&&board[i][j]==board[i][k])
                            return false;
                        int r=row*3+k/3,c=col*3+k%3;
                        if(!(r==i&&c==j)&&board[r][c]==board[i][j])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
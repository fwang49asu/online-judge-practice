class Solution {
public:
    bool isFound(vector<vector<char>> &board, vector<vector<bool>> &visited, string word, int index, int i, int j){
        if(index==word.length())
            return true;
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||visited[i][j]||board[i][j]!=word[index])
            return false;
        visited[i][j]=true;
        if(isFound(board,visited,word,index+1,i+1,j))
            return true;
        if(isFound(board,visited,word,index+1,i,j+1))
            return true;
        if(isFound(board,visited,word,index+1,i-1,j))
            return true;
        if(isFound(board,visited,word,index+1,i,j-1))
            return true;
        visited[i][j]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0)
            return false;
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(isFound(board,visited,word,0,i,j))
                    return true;
            }
        }
        return false;
    }
};
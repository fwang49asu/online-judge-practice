class Solution {
public:
    bool isValid(vector<string>& solution, int m, int n){
        for(int i=0;i<m;i++)
            if(solution[i][n]=='Q')
                return false;
        for(int i=m-1,j=n-1;i>=0&&j>=0;i--,j--)
            if(solution[i][j]=='Q')
                return false;
        for(int i=m-1,j=n+1;i>=0&&j<solution.size();i--,j++)
            if(solution[i][j]=='Q')
                return false;
        return true;
    }
    void dfs(vector<vector<string>>& res, vector<string>& solution, int row){
        if(row==solution.size()){
            res.push_back(solution);
            return;
        }
        for(int i=0;i<solution.size();i++){
            if(isValid(solution,row,i)){
                solution[row][i]='Q';
                dfs(res,solution,row+1);
                solution[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> solution(n, string(n,'.'));
        dfs(res,solution,0);
        return res;
    }
};
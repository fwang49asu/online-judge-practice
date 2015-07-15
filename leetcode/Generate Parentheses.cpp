class Solution {
public:
    void dfs(int lsum, int rsum, int cursum, vector<string> &res, string &line, int n){
        if(cursum==2*n){
            res.push_back(line);
            return;
        }
        if(lsum<n){
            line.push_back('(');
            dfs(lsum+1,rsum,cursum+1,res,line,n);
            line.pop_back();
        }
        if(rsum<lsum){
            line.push_back(')');
            dfs(lsum,rsum+1,cursum+1,res,line,n);
            line.pop_back();            
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string line="";
        dfs(0,0,0,res,line,n);
        return res;
    }
};
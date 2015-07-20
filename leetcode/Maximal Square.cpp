class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxlen=INT_MIN;
        if(matrix.size()==0||matrix[0].size()==0)
            return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]=='1'){
                dp[i][0]=1;
                maxlen=1;
            }
        }
        for(int i=0;i<matrix[0].size();i++){
            if(matrix[0][i]=='1'){
                dp[0][i]=1;
                maxlen=1;
            }
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]=='0')
                    dp[i][j]=0;
                else{
                    dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                    maxlen=max(maxlen,dp[i][j]);
                }
            }
        }
        return maxlen*maxlen;
    }
};
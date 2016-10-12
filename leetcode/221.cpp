class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) {
            return 0;
        }
        int m = matrix[0].size();
        vector<int> dp(m, 0);
        int result = 0;
        for(int i=0; i<m; ++i) {
            dp[i] = matrix[n-1][i] == '1' ? 1 : 0;
            result = max(dp[i], result);
        }
        for(int i=n-1; i>=0; --i) {
            for(int k=0; k<m-1; ++k) {
                if(matrix[i][k] == '0') {
                    dp[k] = 0;
                    continue;
                }
                int min_count = dp[k+1];
                int a = 0;
                for(; a < min_count && k+a+1 < m && matrix[i][k+a+1] == '1'; ++a);
                min_count = min(min_count, a);
                for(a = 0; a < min_count && i+a+1 < n && matrix[i+a+1][k] == '1'; ++a);
                min_count = min(min_count, a);

                dp[k] = min_count + 1;
                result = max(dp[k], result);
            }
            dp[m-1] = matrix[i][m-1] == '1' ? 1 : 0;
            result = max(dp[m-1], result);
        }
        return result * result;
    }
};

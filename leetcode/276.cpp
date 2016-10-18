class Solution {
public:
    int numWays(int n, int k) {
        int dp[] = {0, k, k*k, 0};
        if(n < 3) {
            return dp[n];
        }
        for(int i=3; i<=n; ++i) {
            dp[3] = (k-1)*(dp[1] + dp[2]);
            dp[1] = dp[2];
            dp[2] = dp[3];
        }
        return dp[3];
    }
};

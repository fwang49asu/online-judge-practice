class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int coin : coins) {
            for(int i=coin; i<=amount; ++i) {
                if(dp[i-coin] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i-coin]);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

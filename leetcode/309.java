public class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length <= 1) {
            return 0;
        }
        if(prices.length == 2) {
            return Math.max(prices[1] - prices[0], 0);
        }
        int dp[] = {0, Integer.MIN_VALUE, Integer.MIN_VALUE};
        for(int x: prices) {
            int next[] = {
                Math.max(dp[0], dp[2]),
                Math.max(dp[1], dp[0] - x),
                dp[1] + x
            };
            dp = next;
        }
        return Math.max(dp[0], Math.max(dp[1], dp[2]));
    }
}

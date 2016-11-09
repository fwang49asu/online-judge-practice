public class Solution {
    public int getMoneyAmount(int n) {
        int dp[][] = new int[n+1][n+1];
        return helper(dp, 1, n);
    }

    public int helper(int[][] dp, int left, int right) {
        if(left >= right) {
            return 0;
        }
        if(dp[left][right] > 0) {
            return dp[left][right];
        }
        dp[left][right] = Integer.MAX_VALUE;
        for(int i=left; i<=right; ++i) {
            dp[left][right] = Math.min(dp[left][right], i + Math.max(helper(dp, left, i-1), helper(dp, i+1, right)));
        }
        return dp[left][right];
    }
}

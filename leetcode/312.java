public class Solution {
    public int maxCoins(int[] nums) {
        if(null == nums || 0 == nums.length) {
            return 0;
        }
        int n = nums.length;
        int data[] = new int[n+2];
        for(int i=0; i<n; ++i) {
            data[i+1] = nums[i];
        }
        data[0] = data[n+1] = 1;
        int dp[][] = new int[n+2][n+2];
        for(int right=1; right<n+1; ++right) {
            for(int left = right; left > 0; --left) {
                for(int i=left; i<=right; ++i) {
                    dp[left][right] = Math.max(dp[left][right], dp[left][i-1] + data[left - 1] * data[i] * data[right+1] + dp[i+1][right]);
                }
            }
        }
        return dp[1][n];
    }
}

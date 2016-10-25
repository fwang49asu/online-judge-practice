class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        vector<int> dp(n, 0);
        for(int i=0; i<n; ++i) {
            for(int k=0; k<i; ++k) {
                if(nums[i] > nums[k]) {
                    dp[i] = max(dp[i], dp[k]);
                }
            }
            ++dp[i];
            result = max(result, dp[i]);
        }
        return result;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<int> sum(nums.size(),0);
        int maxval=INT_MIN;
        sum[0]=nums[0];
        maxval=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i]+sum[i-1])
                sum[i]=nums[i]+sum[i-1];
            else
                sum[i]=nums[i];
            maxval=max(maxval,sum[i]);
        }
        return maxval;
    }
};
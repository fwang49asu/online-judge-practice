class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        int* value=new int[n]{0};
        value[0]=nums[0];
        value[1]=max(nums[1],nums[0]);
        for(int i=2;i<n;i++)
            value[i]=max(value[i-2]+nums[i],value[i-1]);
        return value[n-1];
    }
};
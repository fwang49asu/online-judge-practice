class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int res=nums[0];
        int tmpmax=nums[0];
        int tmpmin=nums[0];
        for(int i=1;i<nums.size();i++){
            int a=tmpmax*nums[i];
            int b=tmpmin*nums[i];
            tmpmax=max(nums[i],max(a,b));
            tmpmin=min(nums[i],min(a,b));
            res=max(res,tmpmax);
        }
        return res;
    }
};
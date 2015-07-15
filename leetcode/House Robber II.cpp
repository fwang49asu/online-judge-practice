class Solution {
public:
    int robSub(vector<int>& nums,int start, int end){
        if(start>end)
            return 0;
        if(start==end)
            return nums[start];
        int* value=new int[end-start+1]{0};
        value[0]=nums[start];
        value[1]=max(nums[start+1],nums[start]);
        for(int i=2;i<=end-start;i++)
            value[i]=max(value[i-2]+nums[i+start],value[i-1]);
        return value[end-start];
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        return max(robSub(nums,1,nums.size()-1),robSub(nums,0,nums.size()-2));
    }
};
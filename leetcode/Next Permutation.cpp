class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int loc1=0,loc2=0;
        for(loc1=nums.size()-1;loc1>0;loc1--){
            if(nums[loc1-1]<nums[loc1])
                break;
        }
        if(loc1==0){
            sort(nums.begin(),nums.end());
            return;
        }
        for(loc2=nums.size()-1;loc2>=loc1;loc2--){
            if(nums[loc2]>nums[loc1-1])
                break;
        }
        swap(nums[loc1-1],nums[loc2]);
        sort(nums.begin()+loc1,nums.end());
    }
};
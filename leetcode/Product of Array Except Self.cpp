class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size=nums.size();
        vector<int> res(size,1);
        for(int i=1;i<nums.size();i++)
            res[i]=res[i-1]*nums[i-1];
        int tmp=nums[size-1];
        for(int i=nums.size()-2;i>=0;i--){
            res[i]=res[i]*tmp;
            tmp*=nums[i];
        }
        return res;
    }
};
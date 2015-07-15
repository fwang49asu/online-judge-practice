class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if(nums.size()<=1)
            return nums;
        int n1=0,c1=0;
        int n2=0,c2=0;
        for(int i=0;i<nums.size();i++){
            if(c1==0||nums[i]==n1){
                n1=nums[i];
                c1++;
            }
            else if(c2==0||nums[i]==n2){
                n2=nums[i];
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1=0;
        c2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==n1)
                c1++;
            else if(nums[i]==n2)
                c2++;
        }
        if(c1>nums.size()/3)
            res.push_back(n1);
        if(c2>nums.size()/3&&n1!=n2)
            res.push_back(n2);
        return res;
    }
};
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff=INT_MAX;
        int res=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int start=i+1;
            int end=nums.size()-1;
            while(start<end){
                int tmp=nums[i]+nums[start]+nums[end];
                if(tmp==target){
                    diff=0;
                    res=tmp;
                    break;
                }
                if(tmp<target){
                    int tmpdiff=target-tmp;
                    if(tmpdiff<diff){
                        diff=tmpdiff;
                        res=tmp;
                    }
                    start++;
                }
                else{
                    int tmpdiff=tmp-target;
                    if(tmpdiff<diff){
                        diff=tmpdiff;
                        res=tmp;
                    }
                    end--;                   
                }
            }
            while(i<nums.size()-1&&nums[i]==nums[i+1])
                i++;
        }
        return res;
    }
};
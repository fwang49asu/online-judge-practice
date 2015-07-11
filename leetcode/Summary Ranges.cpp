class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int start=0,end=0;
        if(nums.size()==0)
            return res;
        for(int i=0;i<nums.size();i++){
            start=i;
            end=i;
            while(end<nums.size()-1&&nums[end]+1==nums[end+1])
                end++;
            if(start!=end)
                res.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
            else
                res.push_back(to_string(nums[start]));
            i=end;
        }
        return res;
    }
};
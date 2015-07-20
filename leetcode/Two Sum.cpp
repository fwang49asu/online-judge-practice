class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.size()==0)
            return res;
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]=i+1;
        for(int i=0;i<nums.size();i++){
            if(m.find(target-nums[i])!=m.end()&&m.find(target-nums[i])->second!=i+1){
                res.push_back(i+1);
                res.push_back(m.find(target-nums[i])->second);
                break;
            }
        }
        return res;
    }
};
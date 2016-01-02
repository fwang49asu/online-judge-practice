class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0; i<nums.size(); ++i) {
            for(int k=i+1; k<nums.size(); ++k) {
                if((nums[i] + nums[k]) == target) {
                    result.push_back(i+1);
                    result.push_back(k+1);
                    return result;
                }
            }
        }
    }
};

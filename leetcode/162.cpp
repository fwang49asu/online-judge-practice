class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty()) {
            return -1;
        }
        int peak = 0;
        for(int i=1; i<nums.size(); ++i) {
            if(nums[i] < nums[peak]) {
                return peak;
            }
            peak = i;
        }
        return peak;
    }
};

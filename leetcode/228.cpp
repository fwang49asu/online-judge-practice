class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.empty()) {
            return result;
        }
        int low = nums[0];
        int high = nums[0];
        for(int i=1; i<nums.size(); ++i) {
            if((nums[i] - high) == 1) {
                ++high;
            } else {
                result.push_back(RangeToString(low, high));
                low = nums[i];
                high = nums[i];
            }
        }
        result.push_back(RangeToString(low, high));
        return result;
    }
private:
    string RangeToString(int low, int high) {
        if(low == high) {
            return to_string(low);
        }
        return to_string(low) + "->" + to_string(high);
    }
};

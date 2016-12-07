class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.empty()) {
            return 0;
        }
        int n = nums.size();
        long long prefix = nums[0];
        map<long long, int> prefix_map;
        prefix_map[prefix] = 1;
        int result = (prefix >= lower && prefix <= upper) ? 1 : 0;
        for(int i=1; i<n; ++i) {
            prefix += nums[i];
            auto lower_p = prefix_map.lower_bound(prefix - upper);
            auto upper_p = prefix_map.upper_bound(prefix - lower);
            for(auto p = lower_p; p != upper_p; ++p) {
                result += p->second;
            }
            if(prefix >= lower && prefix <= upper) {
                ++result;
            }
            ++prefix_map[prefix];
        }
        return result;
    }
};

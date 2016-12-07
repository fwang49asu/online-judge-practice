class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int result = 0;
        int n = nums.size();
        int prefix = 0;
        unordered_map<int, int> max_map;
        for(int i=0; i<n; ++i) {
            prefix += nums[i];
            if(prefix == k) {
                result = i+1;
            } else {
                if(max_map.find(prefix-k) != max_map.end()) {
                    result = max(result, i - max_map[prefix-k]);
                }
            }
            if(max_map.find(prefix) == max_map.end()) {
                max_map[prefix] = i;
            }
        }
        return result;
    }
};

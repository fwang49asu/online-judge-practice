class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int n = nums.size();
        int result = 0;
        multimap<int, int> m;
        for(int i=0; i<n; ++i) {
            int cur = 0;
            for(auto it = m.rbegin(); it != m.rend(); ++it) {
                if(it->second < nums[i]) {
                    cur = it->first;
                    break;
                }
            }
            ++cur;
            m.insert(make_pair(cur, nums[i]));
        }
        return m.rbegin()->first;
    }
};

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> s;
        for(int i=0; i<nums.size(); ++i) {
            if(k < s.size()) {
                s.erase(s.find(nums[i - k - 1]));
            }
            multiset<long long>::iterator it = s.lower_bound(nums[i] - t);
            if(it != s.end() && abs(*(it) - nums[i]) <= (long long)t) {
                return true;
            }
            it = s.upper_bound(nums[i] + t);
            if(it != s.end() && abs(*(it) - nums[i]) <= (long long)t) {
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};

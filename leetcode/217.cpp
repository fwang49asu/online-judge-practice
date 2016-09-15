class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> distinct_set;
        for(int x: nums) {
            if(distinct_set.find(x) == distinct_set.end()) {
                distinct_set.insert(x);
            } else {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count_map;
        for(int x: nums) {
            ++count_map[x];
        }
        int n = nums.size();
        vector<vector<int>> buckets(n+1);
        for(auto p: count_map) {
            buckets[p.second].push_back(p.first);
        }
        vector<int> result;
        for(int i=n; i>=0 && result.size() < k; --i) {
            for(int p: buckets[i]) {
                if(result.size() == k) {
                    break;
                }
                result.push_back(p);
            }
        }
        return result;
    }
};

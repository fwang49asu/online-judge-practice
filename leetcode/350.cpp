class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count_map_1;
        unordered_map<int, int> count_map_2;
        for(int x: nums1) {
            ++count_map_1[x];
        }
        for(int x: nums2) {
            ++count_map_2[x];
        }
        vector<int> result;
        for(auto p : count_map_1) {
            int count = min(p.second, count_map_2[p.first]);
            for(int i=0; i<count; ++i) {
                result.push_back(p.first);
            }
        }
        return result;
    }
};

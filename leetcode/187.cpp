class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        int n = s.length();
        if(n < 10) {
            return result;
        }
        n -= 9;
        unordered_map<string, int> count_map;
        for(int i=0; i<n; ++i) {
            ++count_map[s.substr(i, 10)];
        }
        for(auto e: count_map) {
            if(e.second > 1) {
                result.push_back(e.first);
            }
        }
        return result;
    }
};

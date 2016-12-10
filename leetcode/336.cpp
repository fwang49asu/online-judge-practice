class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        unordered_map<string, int> index_map;
        set<int> length_set;
        int n = words.size();
        for(int i=0; i<n; ++i) {
            index_map[words[i]] = i;
            length_set.insert(words[i].length());
        }
        for(int i=0; i<n; ++i) {
            string s = words[i];
            reverse(s.begin(), s.end());
            if(index_map.find(s) != index_map.end() && index_map[s] != i) {
                vector<int> temp{i, index_map[s]};
                result.push_back(temp);
            }
            for(auto it = length_set.begin(); *it < words[i].length(); ++it) {
                // append to the head
                int m = *it;
                s = words[i].substr(words[i].length() - m, m);
                reverse(s.begin(), s.end());
                if(isPalindrome(words[i], 0, words[i].length() - m - 1) && index_map.find(s) != index_map.end()) {
                    vector<int> temp{index_map[s], i};
                    result.push_back(temp);
                }
                s = words[i].substr(0, m);
                reverse(s.begin(), s.end());
                if(isPalindrome(words[i], m, words[i].length() - 1) && index_map.find(s) != index_map.end()) {
                    vector<int> temp{i, index_map[s]};
                    result.push_back(temp);
                }
            }
        }
        return result;
    }

    bool isPalindrome(string& s, int low, int high) {
        for(; low < high; ++low, --high) {
            if(s[low] != s[high]) {
                return false;
            }
        }
        return true;
    }
};

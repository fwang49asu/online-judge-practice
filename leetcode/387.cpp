class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        vector<int> pos(26, 0);
        for(int i=0; i<n; ++i) {
            int index = s[i] - 'a';
            pos[index] += n + i;
        }
        int result = INT_MAX;
        for(auto x: pos) {
            if(x == 0) {
                continue;
            }
            result = min(x, result);
        }
        result -= n;
        return result >= n ? -1 : result;
    }
};

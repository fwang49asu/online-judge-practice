class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, bool> m;
        for(char c: s) {
            m[c] = !m[c];
        }
        bool odd = false;
        for(auto p : m) {
            if(p.second && odd) {
                return false;
            }
            odd |= p.second;
        }
        return true;
    }
};

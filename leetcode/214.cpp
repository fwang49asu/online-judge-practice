class Solution {
public:
    string shortestPalindrome(string s) {
        int suffixIndex = 0;
        for(int i=s.length() - 1; i>=0; --i) {
            if(s[i] == s[suffixIndex]) {
                ++suffixIndex;
            }
        }
        if(suffixIndex == s.length()) {
            return s;
        }
        int sublength = s.length() - suffixIndex;
        string prefix(sublength, 'a');
        for(int i=0; i<sublength; ++i) {
            prefix[i] = s[s.length() - i - 1];
        }
        return prefix + shortestPalindrome(s.substr(0, suffixIndex)) + s.substr(suffixIndex);
    }
};

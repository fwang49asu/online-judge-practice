class Solution {
public:
    string reverseString(string s) {
        int n = s.length();
        stringstream ss;
        for(int i=n-1; i>=0; --i) {
            ss << s[i];
        }
        return ss.str();
    }
};

// first version: backtrace
class Solution {
public:
    bool canWin(string s) {
        string ss = s;
        unordered_map<string, bool> m;
        return helper(ss, m);
    }
    bool helper(string& s, unordered_map<string, bool>& m) {
        if(m.find(s) != m.end()) {
            return m[s];
        }
        int n = s.length();
        for(int i=1; i<n; ++i) {
            if(s[i-1] == '+' && s[i] == '+') {
                s[i-1] = s[i] = '-';
                bool opponent = helper(s, m);
                m[s] = opponent;
                s[i-1] = s[i] = '+';
                if(!opponent) {
                    m[s] = true;
                    return true;
                }
            }
        }
        m[s] = false;
        return false;
    }
};

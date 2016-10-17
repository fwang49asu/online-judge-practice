class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> result;
        int n = s.length();
        for(int i=1; i<n; ++i) {
            if(s[i-1] == '+' && s[i] == '+') {
                string str = s;
                str[i-1] = '-';
                str[i] = '-';
                result.push_back(str);
            }
        }
        return result;
    }
};

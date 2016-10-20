class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int n = words.size();
        int max_len = 0;
        for(string s: words) {
            int len = s.length();
            max_len = max(len, max_len);
        }
        if(max_len != n) {
            return false;
        }
        for(int i=0; i<n; ++i) {
            int y = 0;
            int x = 0;
            for(; y < n && words[y].length() <= i;++y);
            while(y < n && x < words[i].length()) {
                if(words[y][i] != words[i][x]) {
                    return false;
                }
                ++x;
                for(++y; y < n && words[y].length() <= i;++y);
            }
            if(y < n || x < words[i].length()) {
                return false;
            }
        }
        return true;
    }
};

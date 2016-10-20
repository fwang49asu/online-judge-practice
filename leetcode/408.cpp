class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int index[] = {0, 0};
        int n[]= {word.length(), abbr.length()};
        while(index[0] < n[0] && index[1] < n[1]) {
            if(abbr[index[1]] == '0') {
                return false;
            }
            if(abbr[index[1]] >= '1' && abbr[index[1]] <= '9') {
                int high = index[1] + 1;
                for(; high < n[1] && abbr[high] >= '0' && abbr[high] <= '9'; ++high);
                int m = stoi(abbr.substr(index[1], high - index[1]));
                if(m == 0) {
                    return false;
                }
                index[1] = high;
                index[0] += m;
            } else {
                if(word[index[0]] != abbr[index[1]]) {
                    return false;
                }
                ++index[0];
                ++index[1];
            }
        }
        return index[0] == n[0] && index[1] == n[1];
    }
};

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count_vec(26, 0);
        for(char c: magazine) {
            ++count_vec[c - 'a'];
        }
        for(char c: ransomNote) {
            --count_vec[c - 'a'];
            if(count_vec[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count_vec(58, 0);
        for(char c: s) {
            ++count_vec[c - 'A'];
        }
        int odd = 0;
        int result = 0;
        for(int x: count_vec) {
            odd |= x;
            result += x >> 1;
        }
        result <<= 1;
        result += odd & 1;
        return result;
    }
};

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        while(n >= 5) {
            int t = n / 5;
            result += n / 5;
            n = t;
        }
        return result;
    }
};

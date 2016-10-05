class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) {
            return false;
        }
        int mask = 1;
        while((n & mask) == 0) {
            n >>= 1;
        }
        n &= (~mask);
        return n == 0;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t mask = 1;
        int count = 0;
        for(int i=0; i<32; ++i, mask = mask << 1) {
            if(n & mask) {
                ++count;
            }
        }
        return count;
    }
};

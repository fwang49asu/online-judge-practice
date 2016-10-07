class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t mask_left = INT_MIN;
        uint32_t mask_right = 1;
        int result = 0;
        for(int i=0; i<32; ++i, mask_right <<= 1, mask_left >>= 1) {
            result |= (mask_right & n) == 0 ? 0 : mask_left;
        }
        return result;
    }
};

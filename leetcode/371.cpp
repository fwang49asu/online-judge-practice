class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int result = 0;
        for(int i=0; i<32; ++i) {
            int a_bit = (a >> i) & 1;
            int b_bit = (b >> i) & 1;
            int c_bit = a_bit ^ b_bit ^ carry;
            carry = (a_bit & b_bit) | (a_bit & carry) | (b_bit & carry);
            result |= (c_bit << i);
        }
        return result;
    }
};

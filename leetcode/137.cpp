class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0;
        int two = 0;

        // similiar to find the unique number in "double numbers"
        // a a a b:
        // a 0
        // 0 a
        // 0 0
        // b 0
        for(int x : nums) {
            one = (one ^ x) & ~two;
            two = (two ^ x) & ~one;
        }
        return one;
    }
};

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff;
        vector<int> vec;
        vec.push_back(0);
        vec.push_back(0);
        for(int x : nums) {
            if((x & diff) == 0) {
                vec[0] ^= x;
            } else {
                vec[1] ^= x;
            }
        }
        return vec;
    }
};

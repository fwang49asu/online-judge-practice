class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0, y = 0;
        for (int i = 0; i < nums.size(); i++) {
            x ^= ~ y & nums[i];
            y ^= ~ x & nums[i];
        }
        return x;        
    }
};
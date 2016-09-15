class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lowpos = 0;
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i] != 0) {
                nums[lowpos++] = nums[i];
            }
        }
        for(int i=lowpos; i<nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};

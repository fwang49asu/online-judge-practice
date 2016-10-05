class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // boyer moore voting
        int index = 0;
        int count = 1;
        int n = nums.size();
        for(int i=1; i<n; ++i) {
            if(nums[i] == nums[index]) {
                ++count;
            } else {
                --count;
            }
            if(count == 0) {
                index = i;
                count = 1;
            }
        }
        return nums[index];
    }
};

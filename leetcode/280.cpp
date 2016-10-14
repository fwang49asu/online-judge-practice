class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for(int i=1; i<nums.size(); ++i) {
            if(((i&1) == 0 && nums[i-1] < nums[i]) || ((i&1) == 1 && nums[i-1] > nums[i])) {
                swap(nums[i-1], nums[i]);
            }
        }
    }
};

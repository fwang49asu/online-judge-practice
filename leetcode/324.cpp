class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int high = n - 1;
        int low = 0;
        int index = 0;
        auto midp = nums.begin() + (n / 2);
        nth_element(nums.begin(), midp, nums.end());
        int mid = *midp;
        while(index <= high) {
            int vIndex = virtualIndex(index, n);
            int vHigh = virtualIndex(high, n);
            int vLow = virtualIndex(low, n);
            if(nums[vIndex] > mid) {
                swap(nums[vIndex], nums[vLow]);
                ++index;
                ++low;
            } else if(nums[vIndex] < mid) {
                swap(nums[vIndex], nums[vHigh]);
                --high;
            } else {
                ++index;
            }
        }
    }
private:
    int virtualIndex(int i, int n) {
        return (1 + i * 2) % (n | 1);
    }
};

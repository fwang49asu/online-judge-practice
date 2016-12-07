class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int n = nums.size();
        int low = (n + 1) / 2;
        int high = n;
        for(int i=0; i<n; ++i) {
            nums[i] = ((i & 1) == 1) ? temp[--high] : temp[--low];
        }
    }
};

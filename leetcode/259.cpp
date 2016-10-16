class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int result = 0;
        for(int i=0; i<n-2; ++i) {
            int low = i+1;
            int high = n-1;
            int limit = target - nums[i];
            while(low < high) {
                if((nums[low] + nums[high]) >= limit) {
                    --high;
                } else {
                    result += (high - low);
                    ++low;
                }
            }
        }
        return result;
    }
};

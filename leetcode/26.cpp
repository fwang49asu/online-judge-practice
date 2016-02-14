#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int low = 0;
        int high = 0;
        for(; high < nums.size(); ++high) {
            if(nums[low] != nums[high]) {
                ++low;
                nums[low] = nums[high];
            }
        }
        return low + 1;
    }
};

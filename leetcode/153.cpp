#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high) {
            // ordered
            if(nums[low] <= nums[high]) {
                return nums[low];
            }
            if((high - low) == 1) {
                return min(nums[low], nums[high]);
            }

            int center = (low + high) >> 1;
            // left or right?
            // if left is ordered, it is on the right
            if(nums[low] < nums[center]) {
                low = center + 1;
            } else {
                high = center;
            }
        }
        return nums[low];
    }
}l

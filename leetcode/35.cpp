#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            if(nums.empty()) {
                return 0;
            }
            return searchInsert(nums, 0, nums.size() - 1, target);
        }
        int searchInsert(vector<int>& nums, int low, int high, int target) {
            if(nums[low] >= target) {
                return low;
            }
            if(nums[high] < target) {
                return high + 1;
            }
            int center = (low + high) / 2;
            if(nums[center] == target) {
                return center;
            } else if(nums[center] > target) {
                if(center > 0 && nums[center-1] < target) {
                    return center;
                }
                return searchInsert(nums, low, center - 1, target);
            } else {
                if(center < (nums.size() - 1) && nums[center+1] > target) {
                    return center+1;
                }
                return searchInsert(nums, center+1, high, target);
            }
        }
};

int main() {
    Solution s;
    int data[] = {1,3,5,6};
    vector<int> vec(data, data+4);
    cout << s.searchInsert(vec, 7) << endl;
    return 0;
}

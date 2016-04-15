#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            return search(nums, 0, nums.size() - 1, target);
        }
    private:
        bool search(vector<int>& nums, int low, int high, int target) {
            if(low > high) {
                return false;
            }
            if(low == high) {
                return nums[low] == target;
            }
            if(nums[low] < nums[high]) {
                int center = (low + high) / 2;
                if(nums[center] == target) {
                    return true;
                }
                if(nums[center] > target) {
                    return search(nums, low, center - 1, target);
                }
                return search(nums, center+1, high, target);
            }
            int center = (low + high) / 2;
            return nums[center] == target
                || search(nums, low, center - 1, target)
                || search(nums, center+1, high, target);
        }
};

int main() {
    return 0;
}

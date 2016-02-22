#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            return search(nums, 0, nums.size() - 1, target);
        }
        int search(vector<int>& nums, int low, int high,int target) {
            if(low > high) {
                return -1;
            }
            if(nums[low] <= nums[high]) {
                if(nums[low] > target || nums[high] < target) {
                    return -1;
                }
                int center = (low + high) / 2;
                if(target == nums[center]) {
                    return center;
                }
                if(target < nums[center]) {
                    return search(nums, low, center - 1, target);
                } else {
                    return search(nums, center + 1, high, target);
                }
            } else {
                int center = (low + high) / 2;
                int left = search(nums, low, center, target);
                if(left != -1) {
                    return left;
                }
                return search(nums, center+1, high, target);
            }
        }
};

int main() {
    Solution s;
    int data[] = {4, 5, 6, 7, 0, 1, 2};
    vector<int> vec(data, data+7);
    cout << s.search(vec, 2) << endl;
    return 0;
}

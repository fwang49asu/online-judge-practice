#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> result;
            int left = findFirst(nums, 0, nums.size() - 1, target);
            if(left == -1) {
                result.push_back(-1);
                result.push_back(-1);
            } else {
                result.push_back(left);
                int right = findLast(nums, left, nums.size() - 1, target);
                result.push_back(right);
            }
            return result;
        }

    private:
        int findFirst(vector<int>& nums, int low, int high, int target) {
            if(low > high) {
                return -1;
            }
            int center = (low + high) / 2;
            if(nums[center] < target) {
                return findFirst(nums, center+1, high, target);
            } else if(nums[center] > target) {
                return findFirst(nums, low, center-1, target);
            } else {
                if(center > 0 && nums[center-1] == target) {
                    return findFirst(nums, low, center-1, target);
                }
                return center;
            }
        }

        int findLast(vector<int>& nums, int low, int high, int target) {
            if(low > high) {
                return -1;
            }
            int center = (low + high) / 2;
            if(nums[center] < target) {
                return findLast(nums, center+1, high, target);
            } else if(nums[center] > target) {
                return findLast(nums, low, center-1, target);
            } else {
                if(center < (nums.size() - 1) && nums[center+1] == target) {
                    return findLast(nums, center+1, high, target);
                }
                return center;
            }
        }
};

int main() {
    Solution s;
    int data[] = {5, 7, 7, 8, 8, 10};
    vector<int> vec(data, data+6);
    vector<int> result = s.searchRange(vec, 8);
    cout << result[0] << "\t" << result[1] << endl;
    return 0;
}

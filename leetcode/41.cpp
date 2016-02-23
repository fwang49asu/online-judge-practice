#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            if(nums.size() == 0) {
                return 1;
            }
            int result = 1;
            int high = nums.size();
            int low = 0;
            int i = 0;
            for(; i < high && low < high; ++i) {
                if(nums[i] <= 0 || nums[i] > high) {
                    --high;
                    if(i == high) {
                        break;
                    }
                    swap(nums[i], nums[high]);
                    --i;
                } else if(nums[i] == result) {
                    ++result;
                    if(i != low) {
                        swap(nums[i], nums[low]);
                    }
                    i = low;
                    ++low;
                }
            }
            return result;
        }
};

int main() {
    int data[] = {3,4,-1,1};
    vector<int> vec(data, data+4);
    Solution s;
    cout << s.firstMissingPositive(vec) << endl;
    return 0;
}

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            if(nums.empty()) {
                return 0;
            }
            int result = nums[0];
            int cur = nums[0];
            int left = 0;
            for(int i=1; i<nums.size(); ++i) {
                if(cur < 0) {
                    left += cur;
                    cur = 0;
                }
                cur += nums[i];
                result = max(result, cur);
            }
            return result;
        }
};

int main() {
    Solution s;
    int data[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> vec(data, data+9);
    cout << s.maxSubArray(vec) << endl;
    return 0;
}

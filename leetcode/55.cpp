#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
    public:
        bool canJump(vector<int>& nums) {
            if(nums.size() <= 1) {
                return true;
            }
            int limit = nums[0];
            int last = nums.size() - 1;
            for(int i=0; i<=limit; ++i) {
                int next = nums[i] + i;
                if(next >= last) {
                    return true;
                }
                limit = max(limit, next);
            }
            return limit >= last;
        }
};

int main() {
    Solution s;
    int data[] = {2, 3, 1, 1, 4, 3, 2, 1, 0, 4, 1, 2, 3};
    vector<int> vec(data+10, data+13);
    cout << s.canJump(vec) << endl;
    return 0;
}

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int jump(vector<int>& nums) {
            int limit = 0;
            int result = 0;
            int end = 0;
            int start = 0;
            int n = nums.size();
            while(limit < (n-1)) {
                ++result;
                limit = end;
                for(int i=start; i<=end; ++i) {
                    if((nums[i] + i) >= (n-1)) {
                        return result;
                    }
                    if((nums[i] + i) > limit) {
                        limit = nums[i] + i;
                    }
                }
                start = end + 1;
                end = limit;
            }
            return result;
        }
};

int main() {
    int data[] = {1, 2, 3};
    vector<int> vec(data, data+3);
    Solution s;
    cout << s.jump(vec) << endl;
    return 0;
}

#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) {
            return 0;
        }
        int last = nums.size() - 1;
        while(last >= 0 && nums[last] == val) {
            --last;
        }
        for(int i=0; i<=last; ++i) {
            if(nums[i] == val) {
                swap(nums[i], nums[last]);
                while(last >= 0 && nums[last] == val) {
                    --last;
                }
            }
        }
        return last + 1;
    }
};

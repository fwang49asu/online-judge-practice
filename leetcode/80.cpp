#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if(nums.size() == 0) {
                return 0;
            }
            int lastpos = 1;
            int count = 1;
            int last = nums[0];
            for(int i=1; i<nums.size(); ++i) {
                if(last == nums[i]) {
                    ++count;
                    if(count == 2) {
                        nums[lastpos++] = nums[i];
                    }
                } else {
                    count = 1;
                    last = nums[i];
                    nums[lastpos++] = nums[i];
                }
            }
            return lastpos;
        }
};

int main() {
    return 0;
}

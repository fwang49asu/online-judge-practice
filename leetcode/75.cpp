#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        void sortColors(vector<int>& nums) {
            if(nums.size() == 0) {
                return;
            }
            int lastZero = 0;
            int lastTwo = nums.size() - 1;
            for(int i=0; i<=lastTwo; ++i) {
                switch(nums[i]) {
                    case 0:
                        if(lastZero != i) {
                            swap(nums[lastZero], nums[i]);
                            --i;
                        }
                        ++lastZero;
                        break;
                    case 1:
                        break;
                    case 2:
                        if(lastTwo != i) {
                            swap(nums[lastTwo], nums[i]);
                            --i;
                        }
                        --lastTwo;
                        break;
                }
            }
        }
};

int main() {
    return 0;
}

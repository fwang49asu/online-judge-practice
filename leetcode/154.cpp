#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int result = nums[0];
        for(int x: nums) {
            result = min(result, x);
        }
        return result;
    }
};

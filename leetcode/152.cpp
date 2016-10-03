#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int max_to_end = nums[0];
        int min_to_end = nums[0];
        int result = nums[0];
        for(int i=1; i<nums.size(); ++i) {
            int next_max = max(max_to_end * nums[i], nums[i]);
            next_max = max(min_to_end * nums[i], next_max);
            int next_min = min(max_to_end * nums[i], nums[i]);
            next_min = min(min_to_end * nums[i], next_min);
            max_to_end = next_max;
            min_to_end = next_min;
            result = max(max_to_end, result);
        }
        return result;
    }
};

int main() {
    return 0;
}

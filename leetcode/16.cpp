#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = 0;
        int mindist = numeric_limits<int>::max();
        vector<int> nums_sorted = nums;
        sort(nums_sorted.begin(), nums_sorted.end());
        int size = nums_sorted.size();
        for(int i=0; i<size-2;) {
            int x = i+1;
            int y = size-1;
            while(x < y) {
                int sum = nums_sorted[i] + nums_sorted[x] + nums_sorted[y];
                int diff = sum - target;
                
                if(diff == 0) {
                    return target;
                } 
                if(diff < 0) {
                    diff = 0-diff;
                    if(diff < mindist) {
                        mindist = diff;
                        result = sum;
                    }
                    ++x;
                } else {
                    if(diff < mindist) {
                        mindist = diff;
                        result = sum;
                    }
                    --y;
                }
            }
            // skip duplicates
            int prev = nums_sorted[i];
            for(; i< size-2 && nums_sorted[i] == prev; ++i);
        }
        return result;
    }
};

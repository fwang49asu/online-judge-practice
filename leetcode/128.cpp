#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> unused_set(nums.begin(), nums.end());
        int result = 1;
        for(int x : nums) {
            if(unused_set.find(x) == unused_set.end()) {
                continue;
            }
            int low = x-1;
            int high = x+1;
            for(; unused_set.find(low) != unused_set.end(); --low) {
                unused_set.erase(low);
            }
            ++low;
            for(; unused_set.find(high) != unused_set.end(); ++high) {
                unused_set.erase(high);
            }
            --high;
            result = max(result, high - low + 1);
        }
        return result;
    }
};

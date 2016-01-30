#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> nums_sorted = nums;
        sort(nums_sorted.begin(), nums_sorted.end());
        int size = nums_sorted.size();
        for(int i=0; i<size-2; ) {
            int x = i+1;
            int y = size-1;
            while(x < y) {
                int sum = nums_sorted[i] + nums_sorted[x] + nums_sorted[y];
                if(sum == 0) {
                    vector<int> vec;
                    vec.push_back(nums_sorted[i]);
                    vec.push_back(nums_sorted[x]);
                    vec.push_back(nums_sorted[y]);
                    result.push_back(vec);
                    
                    // skip the duplicates
                    int prev = nums_sorted[x];
                    for(; x < y && nums_sorted[x] == prev; ++x);
                    prev = nums_sorted[y];
                    for(; y > x && nums_sorted[y] == prev; --y);
                } else if(sum < 0) {
                    ++x;
                } else {
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

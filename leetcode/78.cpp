#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<int> > subsets(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<vector<int> > result;
            int end = 1 << nums.size();
            for(int i=0; i<end; ++i) {
                vector<int> vec;
                for(int mask = 1, k=0; mask <= i; mask = mask << 1, ++k) {
                    if(i & mask) {
                        vec.push_back(nums[k]);
                    }
                }
                result.push_back(vec);
            }
            return result;
        }
};

int main() {
    return 0;
}

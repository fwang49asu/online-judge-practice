#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<int> > fourSum(vector<int>& nums, int target) {
            vector<vector<int> > result;
            sort(nums.begin(), nums.end());
            int n = nums.size();
            for(int i=0; i<n - 3; ++i) {
                // avoid duplication
                if(0 != i && nums[i] == nums[i-1]) {
                    continue;
                }
                // early exit if no solution behind
                if(nums[i] * 4 > target) {
                    break;
                }
                for(int k = n - 1; k>(i+2); --k) {
                    // avoid duplication
                    if((n - 1) != k && nums[k] == nums[k+1]) {
                        continue;
                    }
                    // early exit
                    if(nums[k] * 4 < target) {
                        break;
                    }
                    int subtarget = target - nums[i] - nums[k];
                    int low = i+1;
                    int high = k-1;
                    while(low < high) {
                        int sum = nums[low] + nums[high];
                        if(sum == subtarget) {
                            int array[] = {nums[i], nums[low], nums[high], nums[k]};
                            vector<int> vec(array, array + 4);
                            result.push_back(vec);
                            // skip the same solutions
                            while(low<high && nums[low] == nums[low+1]) {
                                ++low;
                            }
                            while(low<high && nums[high] == nums[high-1]) {
                                --high;
                            }
                            ++low;
                            --high;
                        } else if(sum < subtarget) {
                            ++low;
                        } else {
                            --high;
                        }
                    }
                }
            }
            return result;
        }
};

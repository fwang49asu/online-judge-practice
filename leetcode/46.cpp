#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<int> > permute(vector<int>& nums) {
            vector<vector<int> > result;
            if(nums.size() == 0) {
                return result;
            }
            permute(nums, 0, result);
            return result;
        }
        void permute(vector<int>& nums, int depth, vector<vector<int> >& result) {
            if(depth == (nums.size() - 1)) {
                vector<int> vec(nums);
                result.push_back(vec);
                return;
            }
            for(int i=depth; i < nums.size(); ++i) {
                swap(nums[depth], nums[i]);
                permute(nums, depth + 1, result);
                swap(nums[depth], nums[i]);
            }
        }
};

int main() {
    int data[] = {1, 2, 3};
    vector<int> nums(data, data+3);
    Solution s;
    vector<vector<int> > result = s.permute(nums);
    for(int i=0; i<result.size(); ++i) {
        for(int k=0; k<result[i].size(); ++k) {
            cout << result[i][k] << "\t";
        }
        cout << endl;
    }
}

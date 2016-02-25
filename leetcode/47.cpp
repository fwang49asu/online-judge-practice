#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<int> > permuteUnique(vector<int>& nums) {
            vector<vector<int> > result;
            if(nums.size() == 0) {
                return result;
            }
            sort(nums.begin(), nums.end());
            int n = nums.size();
            vector<int> buffer;
            vector<bool> used;
            used.resize(n, false);
            dfs(nums, 0, buffer, used, result);
            return result;
        }
    private:
        void dfs(vector<int>& nums, int depth, vector<int>& buffer, vector<bool>& used, vector<vector<int> >& result) {
            int n = nums.size();
            if(depth == n) {
                result.push_back(buffer);
                return;
            }
            for(int i=0; i<n; ++i) {
                if((!used[i]) && (i==0 || nums[i] != nums[i-1] || used[i-1])) {
                    used[i] = true;
                    buffer.push_back(nums[i]);
                    dfs(nums, depth + 1, buffer, used, result);
                    buffer.pop_back();
                    used[i] = false;
                }
            }
        }
};

int main() {
    int data[] = {1, 1, 2};
    vector<int> nums(data, data+3);
    Solution s;
    vector<vector<int> > result = s.permuteUnique(nums);
    for(int i=0; i<result.size(); ++i) {
        for(int k=0; k<result[i].size(); ++k) {
            cout << result[i][k] << "\t";
        }
        cout << endl;
    }
    return 0;
}

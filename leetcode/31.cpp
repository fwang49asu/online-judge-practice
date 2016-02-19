#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            if(nums.size() <= 1) {
                return;
            }
            int n = nums.size();
            int index = n-2;
            for(; index>=0 && nums[index] >= nums[index+1]; --index) ;
            if(index < 0) {
                sort(nums.begin(), nums.end());
                return;
            }
            cout << nums[index] << endl;
            int target = n-1;
            for(; nums[target] <= nums[index]; --target) ;
            swap(nums[target], nums[index]);
            sort(nums.begin() + (index + 1), nums.end());
        }
};

int main() {
    Solution s;
    int array[] = {2, 3, 1};
    vector<int> vec(array, array+3);
    s.nextPermutation(vec);
    for(int x: vec) {
        cout << x << "\t";
    }
    cout << endl;
    return 0;
}

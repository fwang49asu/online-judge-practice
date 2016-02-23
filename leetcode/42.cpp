#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int trap(vector<int>& height) {
            if(height.size() <= 2) {
                return 0;
            }
            int low = 0;
            int high = height.size() - 1;
            int result = 0;
            while(low < high) {
                int top = 0;
                if(height[low] < height[high]) {
                    top = height[low];
                    while(low < high && height[low] <= top) {
                        result += top - height[low];
                        ++low;
                    }
                } else {
                    top = height[high];
                    while(low < high && height[high] <= top) {
                        result += top - height[high];
                        --high;
                    }
                }
            }
            return result;
        }
};

int main() {
    int data[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> vec(data, data+12);
    Solution s;
    cout << s.trap(vec) << endl;
    return 0;
}

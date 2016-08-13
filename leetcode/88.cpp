#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int lastpos = n+m-1;
            if(n == 0) {
                return;
            }
            int p1 = m-1;
            int p2 = n-1;

            for(; lastpos > p1 && p1 >= 0; --lastpos) {
                if(nums1[p1] > nums2[p2]) {
                    nums1[lastpos] = nums1[p1];
                    --p1;
                } else {
                    nums1[lastpos] = nums2[p2];
                    --p2;
                }
            }
            for(; lastpos >= 0 && p2 >= 0; --lastpos, --p2) {
                nums1[lastpos] = nums2[p2];
            }
        }
};

int main() {
    return 0;
}

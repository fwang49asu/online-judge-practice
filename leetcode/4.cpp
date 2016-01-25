#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int size = nums1.size() + nums2.size();

            vector<int>* a = &nums1;
            vector<int>* b = &nums2;
            if(a->size() < b->size()) {
                swap(a, b);
            }
            if(size & 1) {
                return kth(a, b, size / 2 + 1);
            }
            return (kth(a, b, size/2) + kth(a, b, size/2+1) ) * 0.5;
        }

        int kth(vector<int>* nums1, vector<int>* nums2, int k) {
            int n = nums1->size(), m = nums2->size();
            int low = 0;
            int high = n+1;
            while(low <= high) {
                int x = (low + high) / 2;
                if(kth(nums1, x) > kth(nums2, k-x+1)) {
                    high = x - 1;
                } else if(kth(nums1, x+1) < kth(nums2,k-x)) {
                    low = x + 1;
                } else {
                    return max(kth(nums1, x), kth(nums2, k-x));
                }
            }
            return 0;
        }

        int kth(vector<int>* vec, int k) {
            int n = vec->size();
            if(k <= 0) {
                return numeric_limits<int>::min();
            }
            if(k> n) {
                return numeric_limits<int>::max();
            }
            return (*vec)[k-1];
        }

};

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> result;
        if(k == 0) {
            return result;
        }
        int size1 = nums1.size();
        int size2 = nums2.size();
        for(int i=max(k - size2, 0); i<=min(k, size1); ++i) {
            result = max(result, merge(maxNumber(nums1, i), maxNumber(nums2, k-i)));
        }
        return result;
    }
private:
    deque<int> maxNumber(vector<int>& nums, int k) {
        deque<int> result;
        int size = nums.size();
        int drop = size - k;
        for(int x: nums) {
            while(drop > 0 && !result.empty() && result.back() < x) {
                --drop;
                result.pop_back();
            }
            result.push_back(x);
        }
        result.resize(k);
        return result;
    }

    vector<int> merge(deque<int> nums1, deque<int> nums2) {
        vector<int> result;
        int index_1 = 0;
        int index_2 = 0;
        while(!(nums1.empty() && nums2.empty())) {
            if(nums1 > nums2) {
                result.push_back(nums1.front());
                nums1.pop_front();
            } else {
                result.push_back(nums2.front());
                nums2.pop_front();
            }
        }
        return result;
    }
};

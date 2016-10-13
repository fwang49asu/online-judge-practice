class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> vec;
        if(nums.empty()) {
            return vec;
        }
        if(nums.size() == 1) {
            vec.push_back(nums[0]);
            return vec;
        }
        if(nums.size() == 2) {
            vec.push_back(nums[0]);
            vec.push_back(nums[1]);
            if(nums[0] == nums[1]) {
                vec.pop_back();
            }
            return vec;
        }
        int major[] = {nums[0], nums[0]};
        int count[] = {0, 0};
        for(int x : nums) {
            if(x == major[0]) {
                ++count[0];
            } else if(x == major[1]) {
                ++count[1];
            } else if(count[0] == 0) {
                major[0] = x;
                count[0] = 1;
            } else if(count[1] == 0) {
                major[1] = x;
                count[1] = 1;
            } else {
                --count[0];
                --count[1];
            }
        }
        count[0] = 0;
        count[1] = 0;
        for(int x: nums) {
            if(major[0] == x) {
                ++count[0];
            } else if(major[1] == x) {
                ++count[1];
            }
        }
        int bar = nums.size() / 3;
        if(count[0] > bar) {
            vec.push_back(major[0]);
        }
        if(count[1] > bar) {
            vec.push_back(major[1]);
        }
        return vec;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> result;
        for(int i=0; i<n; ++i) {
            int another = bisearch(numbers, i+1, n-1, target - numbers[i]);
            if(another != -1) {
                result.push_back(i+1);
                result.push_back(another+1);
                break;
            }
        }
        return result;
    }
private:
    int bisearch(vector<int>& nums, int low, int high, int val) {
        if(low > high) {
            return -1;
        }
        int center = (low + high) >> 1;
        if(nums[center] == val) {
            return center;
        } else if(nums[center] > val) {
            return bisearch(nums, low, center - 1, val);
        }
        return bisearch(nums, center + 1, high, val);
    }
};

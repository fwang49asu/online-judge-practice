class NumArray {
public:
    NumArray(vector<int> &nums) {
        prefix = vector<int>(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=1; i<n; ++i) {
            prefix[i] += prefix[i-1];
        }
    }

    int sumRange(int i, int j) {
        if(i == 0) {
            return prefix[j];
        }
        return prefix[j] - prefix[i-1];
    }
private:
    vector<int> prefix;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

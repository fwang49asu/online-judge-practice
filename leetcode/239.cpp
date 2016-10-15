class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();
        if(n == 0 || k== 0) {
            return result;
        }
        if(k > n) {
            k = n;
        }
        // first version: priority queue
        multiset<int> s;
        for(int i=0; i<k; ++i) {
            s.insert(nums[i]);
        }
        for(int i=1; (i+k-1) < n; ++i) {
            multiset<int>::iterator it = s.end();
            --it;
            result.push_back(*it);
            s.erase(s.find(nums[i-1]));
            s.insert(nums[i+k-1]);
        }
        {
            multiset<int>::iterator it = s.end();
            --it;
            result.push_back(*it);
        }
        return result;
    }
};

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
        // second version: decreasing dequeue
        deque<int> q;
        for(int i=0; i<n; ++i) {
            // add it into the queue
            while(!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            if(i >= (k-1)) {
                if(q.front() == (i-k)) {
                    q.pop_front();
                }
                result.push_back(nums[q.front()]);
            }
        }
        return result;
    }
};

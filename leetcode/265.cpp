class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n == 0) {
            return 0;
        }
        int m = costs[0].size();
        if(m == 0) {
            return 0;
        }
        vector<int> prev(costs[0].begin(), costs[0].end());
        for(int i=1; i<n; ++i) {
            int min_index = 0;
            int second_index = 0;
            if(prev[0] <= prev[1]) {
                min_index = 0;
                second_index = 1;
            } else {
                min_index = 1;
                second_index = 0;
            }
            for(int k=2; k<m; ++k) {
                if(prev[k] < prev[min_index]) {
                    second_index = min_index;
                    min_index = k;
                    continue;
                }
                if(prev[k] < prev[second_index]) {
                    second_index = k;
                }
            }
            assert(min_index != second_index);
            vector<int> cur(costs[i].begin(), costs[i].end());
            for(int k=0; k<m; ++k) {
                cur[k] += prev[k == min_index ? second_index : min_index];
            }
            prev.swap(cur);
        }
        return accumulate(prev.begin(), prev.end(), prev.front(), [](const int& a, const int& x) -> int {
            return min(a, x);
        });
    }
};

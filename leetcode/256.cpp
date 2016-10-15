class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.empty()) {
            return 0;
        }
        int prev[] = {0, 0, 0};
        for(int i=0; i<3; ++i) {
            prev[i] = costs[0][i];
        }
        int n = costs.size();
        for(int i=1; i<n; ++i) {
            int cur[] = {
                min(prev[1], prev[2]) + costs[i][0],
                min(prev[0], prev[2]) + costs[i][1],
                min(prev[0], prev[1]) + costs[i][2]
            };
            for(int k=0; k<3; ++k) {
                prev[k] = cur[k];
            }
        }
        return min(prev[0], min(prev[1], prev[2]));
    }
};

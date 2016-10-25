class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) {
            return 0;
        }
        int m = grid[0].size();
        if(m == 0) {
            return 0;
        }
        vector<int> col_count(m, 0);
        vector<int> row_count(n, 0);
        for(int i=0; i<n; ++i) {
            for(int k=0; k<m; ++k) {
                if(grid[i][k] == 1) {
                    ++col_count[k];
                    ++row_count[i];
                }
            }
        }
        return minTotalDistance(col_count) + minTotalDistance(row_count);
    }

    int minTotalDistance(vector<int>& vec) {
        int n = vec.size();
        vector<int> right(n, 0);
        vector<int> left(n, 0);
        left[0] = 0;
        for(int i=1; i<n; ++i) {
            left[i] = left[i-1] + vec[i-1];
        }
        right[n-1] = vec[n-1];
        for(int i=n-2; i>=0; --i) {
            right[i] = right[i+1] + vec[i];
        }
        int cur = accumulate(right.begin(), right.end(), 0);
        int result = cur;
        for(int i=0; i<n; ++i) {
            cur = cur - right[i] + left[i];
            result = min(cur, result);
        }
        return result;
    }
};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) {
            return 0;
        }
        int m = matrix[0].size();
        if(m == 0) {
            return 0;
        }
        vector<vector<int>> path_len;
        for(int i=0; i<n; ++i) {
            path_len.push_back(vector<int>(m, -1));
        }
        int result = 0;
        for(int i=0; i<n; ++i) {
            for(int k=0; k<m; ++k) {
                result = max(result, dfs(matrix, path_len, i, k, n, m));
            }
        }
        return result;
    }
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& path_len, int y, int x, int n, int m) {
        if(path_len[y][x] != -1) {
            return path_len[y][x];
        }
        int offset[] = {-1, 0, 1, 0, -1};
        int pos[2];
        path_len[y][x] = 1;
        for(int i=0; i<4; ++i) {
            pos[0] = y + offset[i];
            pos[1] = x + offset[i+1];
            if(pos[0] >= 0 && pos[0] < n && pos[1] >= 0 && pos[1] < m && matrix[pos[0]][pos[1]] > matrix[y][x]) {
                path_len[y][x] = max(path_len[y][x], 1 + dfs(matrix, path_len, pos[0], pos[1], n, m));
            }
        }
        return path_len[y][x];
    }
};

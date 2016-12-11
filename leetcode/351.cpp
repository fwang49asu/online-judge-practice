class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> skips;
        for(int i=0; i<10; ++i) {
            skips.push_back(vector<int>(10, 0));
        }
        skips[1][3] = skips[3][1] = 2;
        skips[1][7] = skips[7][1] = 4;
        skips[3][9] = skips[9][3] = 6;
        skips[7][9] = skips[9][7] = 8;
        skips[1][9] = skips[9][1] = skips[3][7] = skips[7][3] = skips[2][8] = skips[8][2] = skips[4][6] = skips[6][4] = 5;
        vector<bool> used(10, false);
        int result = 0;
        for(int i=m; i<=n; ++i) {
            result += dfs(skips, used, 1, i-1) * 4;
            result += dfs(skips, used, 2, i-1) * 4;
            result += dfs(skips, used, 5, i-1);
        }
        return result;
    }
    int dfs(vector<vector<int>>& skips, vector<bool>& used, int pos, int depth) {
        if(depth < 0) {
            return 0;
        }
        if(depth == 0) {
            return 1;
        }
        used[pos] = true;
        int result = 0;
        for(int i=1; i<=9; ++i) {
            if(i != pos && !used[i] && (skips[i][pos] == 0 || used[skips[i][pos]])) {
                result += dfs(skips, used, i, depth-1);
            }
        }
        used[pos] = false;
        return result;
    }
};

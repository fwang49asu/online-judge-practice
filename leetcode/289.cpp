class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        if(n == 0) {
            return;
        }
        int m = board[0].size();
        for(int i=0; i<n; ++i) {
            for(int k=0; k<m; ++k) {
                board[i][k] |= NextCell(board, n, m, i, k) << 1;
            }
        }
        for(int i=0; i<n; ++i) {
            for(int k=0; k<m; ++k) {
                board[i][k] >>= 1;
            }
        }
    }
    int NextCell(vector<vector<int>>& board, int n, int m, int y, int x) {
        int count = 0;
        int min_x = max(0, x-1);
        int max_x = min(m-1, x+1);
        int min_y = max(0, y-1);
        int max_y = min(n-1, y+1);
        for(int i=min_y; i<=max_y; ++i) {
            for(int k=min_x; k<=max_x; ++k) {
                count += board[i][k] & 1;
            }
        }
        count -= board[y][x] & 1;
        if((board[y][x] & 1) == 1) {
            if(count < 2 || count > 3) {
                return 0;
            }
            return 1;
        }
        return count == 3 ? 1 : 0;
    }
};

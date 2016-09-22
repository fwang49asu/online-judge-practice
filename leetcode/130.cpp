class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // only scan the borders
        // upper
        int n = board.size();
        if(n == 0) {
            return;
        }
        int m = board[1].size();
        if(m == 0) {
            return;
        }
        for(int i=0; i<m; ++i) {
            flood(board, 0, i);
            flood(board, n-1, i);
        }
        for(int i=1; i<n; ++i) {
            flood(board, i, 0);
            flood(board, i, m-1);
        }

        for(int i=0; i<n; ++i) {
            for(int k=0; k<m; ++k) {
                board[i][k] = reverse(board[i][k]);
            }
        }

    }

    inline char reverse(char c) {
        switch(c) {
        case 'X':
            return 'X';
        case 'O':
            return 'X';
        case '+':
            return 'O';
        }
        return 'X';
    }

    void flood(vector<vector<char>>& board, int y, int x) {
        int n = board.size();
        int m = board[0].size();
        if(y < 0 || y >= n || x < 0 || x >= m) {
            return;
        }
        if(board[y][x] != 'O') {
            return;
        }
        stack<pair<int, int>> s;
        s.push(make_pair(y, x));
        while(!s.empty()) {
            pair<int, int> p = s.top();
            s.pop();
            board[p.first][p.second] = '+';
            if(p.first >= 1 && board[p.first-1][p.second] == 'O') {
                s.push(make_pair(p.first-1, p.second));
            }
            if(p.first < n-1 && board[p.first+1][p.second] == 'O') {
                s.push(make_pair(p.first+1, p.second));
            }
            if(p.second >= 1 && board[p.first][p.second-1] == 'O') {
                s.push(make_pair(p.first, p.second-1));
            }
            if(p.second < m-1 && board[p.first][p.second+1] == 'O') {
                s.push(make_pair(p.first, p.second+1));
            }
        }


        flood(board, y-1, x);
        flood(board, y+1, x);
        flood(board, y, x-1);
        flood(board, y, x+1);
    }
};

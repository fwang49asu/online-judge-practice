#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        bool exist(vector<vector<char> >& board, string word) {
            vector<vector<bool> > used;
            int n = board.size();
            if(n == 0) {
                return false;
            }
            int m = board[0].size();
            if(m == 0) {
                return false;
            }
            int length = word.length();
            if(length == 0) {
                return true;
            }
            for(int i=0; i<n; ++i) {
                vector<bool> vec;
                vec.resize(m, false);
                used.push_back(vec);
            }
            int c = word[0];
            for(int i=0; i<n; ++i) {
                for(int k=0; k<m; ++k) {
                    if(c == board[i][k] && exist(board, used, i, k, n, m, word, 0)) {
                        return true;
                    }
                }
            }
            return false;
        }

        bool exist(vector<vector<char> >& board, vector<vector<bool> >& used, int y, int x, int n, int m, string& word, int index) {
            if(index == (word.length()-1)) {
                return true;
            }
            used[y][x] = true;
            ++index;
            char c = word[index];
            if(y>0 && c == board[y-1][x] && !used[y-1][x] && exist(board, used, y-1, x, n, m, word, index)) {
                return true;
            }
            if(y<(n-1) && c == board[y+1][x] && !used[y+1][x] && exist(board, used, y+1, x, n, m, word, index)) {
                return true;
            }
            if(x>0 && c == board[y][x-1] && !used[y][x-1] && exist(board, used, y, x-1, n, m, word, index)) {
                return true;
            }
            if(x<(m-1) && c == board[y][x+1] && !used[y][x+1] && exist(board, used, y, x+1, n, m, word, index)) {
                return true;
            }
            used[y][x] = false;
            return false;
        }
};

int main() {
    return 0;
}

#include <vector>
#include <iostream>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
    public:
        void solveSudoku(vector<vector<char> >& board) {
            stack<int> work_stack;
            for(int i=0; i<9; ++i) {
                for(int k=0; k<9; ++k) {
                    if(board[i][k] == '.') {
                        work_stack.push(i*9 + k);
                    }
                }
            }
            solveSudoku(board, work_stack);
        }

    private:
        bool solveSudoku(vector<vector<char> >& board, stack<int>& work_stack) {
            if(work_stack.empty()) {
                return true;
            }
            int top = work_stack.top();
            int y = top / 9;
            int x = top % 9;

            for(char c = '1'; c <= '9'; ++c) {
                if(check(board, y, x, c)) {
                    board[y][x] = c;
                    work_stack.pop();
                    if(solveSudoku(board, work_stack)) {
                        return true;
                    }
                    board[y][x] = '.';
                    work_stack.push(top);
                }
            }
            return false;
        }

        bool check(vector<vector<char> >& board, int y, int x, char c) {
            // row
            for(int i=0; i<9; ++i) {
                if(board[y][i] == c) {
                    return false;
                }
            }
            // column
            for(int i=0; i<9; ++i) {
                if(board[i][x] == c) {
                    return false;
                }
            }
            // square
            int p = y / 3;
            int q = x / 3;
            for(int i=0; i<3; ++i) {
                for(int k=0; k<3; ++k) {
                    if(board[p*3 + i][q*3+k] == c) {
                        return false;
                    }
                }
            }
            return true;
        }
};

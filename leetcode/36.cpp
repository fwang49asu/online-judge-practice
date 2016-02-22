#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        bool isValidSudoku(vector<vector<char> >& board) {
            int mask;
            // row
            for(int i=0; i<9; ++i) {
                mask = 0;
                for(int k=0; k<9; ++k) {
                    char c = board[i][k];
                    if(c != '.') {
                        int diff = c - '1';
                        int pos = 1 << diff;
                        if(pos & mask) {
                            return false;
                        }
                        mask |= pos;
                    }
                }
            }
            // column
            for(int i=0; i<9; ++i) {
                mask = 0;
                for(int k=0; k<9; ++k) {
                    char c = board[k][i];
                    if(c != '.') {
                        int diff = c - '1';
                        int pos = 1 << diff;
                        if(pos & mask) {
                            return false;
                        }
                        mask |= pos;
                    }
                }
            }
            // square
            for(int i=0; i<9; i+=3) {
                for(int k=0; k<9; k+=3) {
                    mask = 0;
                    for(int y=0; y<3; ++y) {
                        for(int x=0; x<3; ++x) {
                            char c = board[y+i][x+k];
                            if(c != '.') {
                                int diff = c - '1';
                                int pos = 1 << diff;
                                if(pos & mask) {
                                    return false;
                                }
                                mask |= pos;
                            }
                        }
                    }
                }
            }
            return true;
        }
};

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        int totalNQueens(int n) {
            if(n == 0 || n==2 || n==3) {
                return 0;
            }
            if(n == 1) {
                return 1;
            }
            vector<string> vec(n);
            for(int i=0; i<n; ++i) {
                vec[i] = "";
                for(int k=0; k<n; ++k) {
                    vec[i] += '.';
                }
            }
            int result = 0;
            solveNQueens(n, 0, vec, result);
            return result;
        }
    private:
        void solveNQueens(int n, int depth, vector<string>& buffer, int& result) {
            if(depth == n) {
                ++result;
                return;
            }
            for(int i=0; i<n; ++i) {
                if(check(buffer, depth, i, n)) {
                    buffer[depth][i] = 'Q';
                    solveNQueens(n, depth+1, buffer, result);
                    buffer[depth][i] = '.';
                }
            }
        }
        bool check(vector<string>& vec, int y, int x, int n) {
            for(int i=0; i<y; ++i) {
                if(vec[i][x] == 'Q') {
                    return false;
                }
            }
            for(int i=1; (y-i) >=0 && (x+i) < n; ++i) {
                if(vec[y-i][x+i] == 'Q') {
                    return false;
                }
            }
            for(int i=1; (y-i) >=0 && (x-i) >= 0 ; ++i) {
                if(vec[y-i][x-i] == 'Q') {
                    return false;
                }
            }
            return true;
        }

};

int main() {
    Solution s;
    cout << s.totalNQueens(4) << endl;
    return 0;
}

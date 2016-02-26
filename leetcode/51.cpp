#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        vector<vector<string> > solveNQueens(int n) {
            vector<vector<string> > result;
            vector<string> vec(n);
            for(int i=0; i<n; ++i) {
                vec[i] = "";
                for(int k=0; k<n; ++k) {
                    vec[i] += '.';
                }
            }
            solveNQueens(n, 0, vec, result);
            return result;
        }
    private:
        void solveNQueens(int n, int depth, vector<string>& buffer, vector<vector<string> >& result) {
            if(depth == n) {
                result.push_back(buffer);
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
    vector<vector<string> > result = s.solveNQueens(4);
    for(int i=0; i<result.size(); ++i) {
        for(int k=0; k<result[i].size(); ++k) {
            cout << result[i][k] << endl;
        }
        cout << endl;
    }
    return 0;
}

#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        void setZeroes(vector<vector<int> >& matrix) {
            int n = matrix.size();
            if(n == 0) {
                return;
            }
            int m = matrix[0].size();
            bool columnZero = false;
            bool rowZero = false;
            for(int i=0; i<n; ++i) {
                columnZero |= matrix[i][0] == 0;
            }
            for(int i=0; i<m; ++i) {
                rowZero |= matrix[0][i] == 0;
            }
            for(int i=1; i<n; ++i) {
                for(int k=1; k<m; ++k) {
                    if(matrix[i][k] == 0) {
                        matrix[i][0] = 0;
                        matrix[0][k] = 0;
                    }
                }
            }
            for(int i=1; i<n; ++i) {
                if(matrix[i][0] == 0) {
                    for(int k=1; k<m; ++k) {
                        matrix[i][k] = 0;
                    }
                }
            }
            for(int k=1; k<m; ++k) {
                if(matrix[0][k] == 0) {
                    for(int i=1; i<n; ++i) {
                        matrix[i][k] = 0;
                    }
                }
            }
            if(columnZero) {
                for(int i=0; i<n; ++i) {
                    matrix[i][0] = 0;
                }
            }
            if(rowZero) {
                for(int i=0; i<m; ++i) {
                    matrix[0][i] = 0;
                }
            }
        }
};

int main() {
    return 0;
}

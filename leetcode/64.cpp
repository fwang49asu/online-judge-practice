#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int minPathSum(vector<vector<int> >& grid) {
            int n = grid.size();
            int m = grid[0].size();

            int** data = new int*[n];
            for(int i=0; i<n; ++i) {
                data[i] = new int[m];
            }

            data[0][0] = grid[0][0];
            for(int i=1; i<n; ++i) {
                data[i][0] = data[i-1][0] + grid[i][0];
            }
            for(int i=1; i<m; ++i) {
                data[0][i] = data[0][i-1] + grid[0][i];
            }
            for(int i=1; i<n; ++i) {
                for(int k=1; k<m; ++k) {
                    data[i][k] = min(data[i-1][k], data[i][k-1]) + grid[i][k];
                }
            }
            int result = data[n-1][m-1];

            for(int i=0; i<n; ++i) {
                delete[] data[i];
            }
            delete[] data;
            return result;
        }
};

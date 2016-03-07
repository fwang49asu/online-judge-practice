#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
            int n = obstacleGrid.size();
            int m = obstacleGrid[0].size();
            vector<int> buffer(m, 0);
            buffer[0] = obstacleGrid[0][0] == 0 ? 1 : 0;
            for(int i=0; i<n; ++i) {
                buffer[0] &= obstacleGrid[i][0] == 0 ? 1 : 0;
                for(int k=1; k<m; ++k) {
                    buffer[k] = obstacleGrid[i][k] == 0 ? buffer[k-1] + buffer[k] : 0;
                }
            }
            return buffer.back();
        }
};

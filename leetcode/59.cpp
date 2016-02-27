#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        vector<vector<int> > generateMatrix(int n) {
            vector<vector<int> > result;
            for(int i=0; i<n; ++i) {
                result.push_back(vector<int>(n));
            }
            int top = 0;
            int bottom = n-1;
            int left = 0;
            int right = n-1;
            int x = 0;
            while(top <= bottom && left <= right) {
                for(int i=left; i<=right; ++i) {
                    result[top][i] = ++x;
                }
                ++top;
                if(top > bottom || left > right) {
                    break;
                }
                for(int i=top; i<=bottom; ++i) {
                    result[i][right] = ++x;
                }
                --right;
                if(top > bottom || left > right) {
                    break;
                }
                for(int i=right; i>=left; --i) {
                    result[bottom][i] = ++x;
                }
                --bottom;
                if(top > bottom || left > right) {
                    break;
                }
                for(int i=bottom; i>=top; --i) {
                    result[i][left] = ++x;
                }
                ++left;

            }
            return result;
        }
};

int main() {
    Solution s;
    vector<vector<int> > result = s.generateMatrix(3);
    for(int i=0; i<result.size(); ++i) {
        for(int k=0; k<result[i].size(); ++k) {
            cout << result[i][k] << "\t";
        }
        cout << endl;
    }
    return 0;
}

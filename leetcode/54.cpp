#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int> >& matrix) {
            vector<int> result;
            if(matrix.empty() || matrix[0].empty()) {
                return result;
            }
            int N = matrix.size();
            int M = matrix[0].size();
            int top = 0;
            int bottom = N-1;
            int left = 0;
            int right = M-1;
            while(top <= bottom && left <= right) {
                for(int i=left; i<=right; ++i) {
                    result.push_back(matrix[top][i]);
                }
                ++top;
                if(top > bottom || left > right) {
                    break;
                }
                for(int i=top; i<=bottom; ++i) {
                    result.push_back(matrix[i][right]);
                }
                --right;
                if(top > bottom || left > right) {
                    break;
                }
                for(int i=right; i>=left; --i) {
                    result.push_back(matrix[bottom][i]);
                }
                --bottom;
                if(top > bottom || left > right) {
                    break;
                }
                for(int i=bottom; i>=top; --i) {
                    result.push_back(matrix[i][left]);
                }
                ++left;
            }
            return result;
        }
};

int main() {
    int data[] = {2, 3, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<vector<int> > matrix;
    for(int i=0; i<2; i+=2) {
        vector<int> vec(data+i, data+i+2);
        matrix.push_back(vec);
    }
    Solution s;
    vector<int> result = s.spiralOrder(matrix);
    for(int i=0; i<result.size(); ++i) {
        cout << result[i] << endl;
    }
    return 0;
}

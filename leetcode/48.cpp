#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void rotate(vector<vector<int> >& matrix) {
            int n = matrix.size();
            int half = n / 2;
            for(int i=0; i<half; ++i) {
                int start = i;
                int end = n-1-i;
                int length = end - start;
                for(int k=0; k<length; ++k) {
                    int t = matrix[start][start + k];
                    matrix[start][start+k] = matrix[end-k][start];
                    matrix[end-k][start] = matrix[end][end-k];
                    matrix[end][end-k] = matrix[start+k][end];
                    matrix[start+k][end] = t;
                } 
            }
        }
};

int main() {
    int n = 2;
    int data[] = {1, 2, 3, 4};
    vector<int> vec(data, data+2);
    vector<vector<int> > matrix;
    matrix.push_back(vec);
    vec = vector<int>(data+2, data+4);
    matrix.push_back(vec);

    for(int i=0; i<n; ++i) {
        for(int k=0; k<n; ++k) {
            cout << matrix[i][k] << "\t";
        }
        cout << endl;
    }
    Solution s;
    s.rotate(matrix);
    for(int i=0; i<n; ++i) {
        for(int k=0; k<n; ++k) {
            cout << matrix[i][k] << "\t";
        }
        cout << endl;
    }
    return 0;
}

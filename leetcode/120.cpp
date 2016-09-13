#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        if(size == 0) {
            return 0;
        }
        vector<int> lower;
        vector<int> upper;
        for(int i=0; i<size; ++i) {
            lower.push_back(triangle[size-1][i]);
        }
        for(int i=0; i<size; ++i) {
            upper.push_back(0);
        }
        for(int i=size-2; i>=0; --i) {
            for(int k=0; k<=i; ++k) {
                upper[k] = min(lower[k], lower[k+1]) + triangle[i][k];
            }
            lower.swap(upper);
        }
        return lower[0];
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<vector<int>> input;
    srand(time(NULL));
    for(int i=1; i<=4; ++i) {
        vector<int> vec;
        for(int k=0; k<i; ++k) {
            vec.push_back(rand() % 10);
        }
        input.push_back(vec);
    }

    for(auto vec : input) {
        for(int a : vec) {
            cout << a << " ";
        }
        cout << endl;
    }
    cout << s.minimumTotal(input) << endl;
    return 0;
}

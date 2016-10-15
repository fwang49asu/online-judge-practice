#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) {
            return false;
        }
        int m = matrix[0].size();
        if(m == 0) {
            return false;
        }
        return SearchMatrix(matrix, target, 0, m-1, 0, n-1);
    }
private:
    bool SearchMatrix(vector<vector<int>>& matrix, int target, int left, int right, int low, int high) {
        if(left > right || low > high) {
            return false;
        }
        if(low == high) {
            return SearchRow(matrix, target, low, left, right);
        }
        if(left == right) {
            return SearchColumn(matrix, target, left, low, high);
        }
        int center_x = (left + right) >> 1;
        int center_y = (low + high) >> 1;

        if(matrix[center_y][center_x] == target) {
            return true;
        }
        if(matrix[center_y][center_x] > target) {
            return SearchMatrix(matrix, target, left, center_x-1, low, high)
                || SearchMatrix(matrix, target, center_x, right, low, center_y - 1);
        }
        return SearchMatrix(matrix, target, center_x+1, right, low, high)
            || SearchMatrix(matrix, target, left, center_x, center_y+1, high);
    }
    bool SearchColumn(vector<vector<int>>& matrix, int target, int column, int low, int high) {
        while(low <= high) {
            int center = (low + high) >> 1;
            if(matrix[center][column] == target) {
                return true;
            }
            if(matrix[center][column] > target) {
                high = center - 1;
                continue;
            }
            low = center + 1;
            continue;
        }
        return false;
    }
    bool SearchRow(vector<vector<int>>& matrix, int target, int row, int left, int right) {
        while(left <= right) {
            int center = (left + right) >> 1;
            if(matrix[row][center] == target) {
                return true;
            }
            if(matrix[row][center] > target) {
                right = center - 1;
                continue;
            }
            left = center + 1;
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix;
    int n, m, target;
    cin >> n >> m >> target;
    for(int i=0; i<n; ++i) {
        vector<int> vec;
        for(int k=0; k<m; ++k) {
            int x;
            cin >> x;
            vec.push_back(x);
        }
        matrix.push_back(vec);
    }
    Solution s;
    cout << s.searchMatrix(matrix, target) <<endl;
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        bool searchMatrix(vector<vector<int> >& matrix, int target) {
            int n = matrix.size();
            if(n == 0) {
                return false;
            }
            int m = matrix[0].size();
            if(m == 0) {
                return false;
            }
            int index = searchHead(matrix, target, 0, n-1, m);
            if(index == -1) {
                return false;
            }
            return searchVector(matrix[index], target, 0, m-1);
        }
    private:
        bool searchVector(vector<int>& vec, int target, int low, int high) {
            if(low > high) {
                return false;
            }
            int center = (low + high) >> 1;
            if(vec[center] == target) {
                return true;
            }
            if(vec[center] > target) {
                return searchVector(vec, target, low, center - 1);
            }
            if(vec[center] < target) {
                return searchVector(vec, target, center+1, high);
            }
        }
        int searchHead(vector<vector<int> >& matrix, int target, int low, int high, int m) {
            if(low > high) {
                return -1;
            }
            if(matrix[low][0] > target || matrix[high][m-1] < target) {
                return -1;
            }
            int center = (low + high) >> 1;
            if(matrix[center][0] <= target && matrix[center][m-1] >= target) {
                return center;
            }
            if(matrix[center][0] > target) {
                return searchHead(matrix, target, low, center - 1, m);
            }
            if(matrix[center][m-1] < target) {
                return searchHead(matrix, target, center+1, high, m);
            }
            return -1;
        }
};

int main() {
    vector<vector<int> > matrix;
    {
        vector<int> a;
        a.push_back(1);
        matrix.push_back(a);
    }
    {
        vector<int> a;
        a.push_back(3);
        matrix.push_back(a);
    }
    Solution s;
    cout << s.searchMatrix(matrix, 3) << endl;
}

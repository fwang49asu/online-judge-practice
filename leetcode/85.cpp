#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
    private:
        int largestRectangleArea(vector<int>& heights) {
            for(int i=0; i<heights.size(); ++i) {
                cout << heights[i] << " ";
            }
            cout << endl;
            int result = 0;
            stack<int> index_stack;
            heights.push_back(0);

            for(int i=0; i<heights.size(); ++i) {
                if(index_stack.empty() || heights[index_stack.top()] <= heights[i]) {
                    index_stack.push(i);
                } else {
                    int temp = heights[index_stack.top()];
                    index_stack.pop();
                    int tempSum = 0;
                    if(index_stack.empty()) {
                        tempSum = temp * i;
                    } else {
                        tempSum = temp * (i - index_stack.top());
                    }
                    result = max(result, tempSum);
                    --i;
                }
            }
            heights.pop_back();
            return result;
        }

    public:
        int maximalRectangle(vector<vector<char> >& matrix) {
            int result = 0;
            vector<int> heights;
            int N = matrix.size();
            if(N==0) {
                return 0;
            }
            int M = matrix[0].size();
            if(M==0) {
                return 0;
            }
            for(int i=0; i<M; ++i) {
                heights.push_back(0);
            }
            for(int row = N-1; row >= 0; --row) {
                // construct the heights
                for(int i=0; i<M; ++i) {
                    heights[i] = matrix[row][i] == '0' ? 0 : (heights[i] + 1);
                }
                result = max(largestRectangleArea(heights), result);
            }
            return result;
        }
};

int main() {
    string array[] = {"01"};
    vector<vector<char> > matrix;
    for(int i=0; i<1; ++i) {
        vector<char> v(array[i].begin(), array[i].end());
        matrix.push_back(v);
    }
    Solution s;
    cout << s.maximalRectangle(matrix) << endl;
    return 0;
}

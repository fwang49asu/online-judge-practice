#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            heights.push_back(0);
            stack<int> index_stack;
            int result = 0;
            for(int i=0; i<heights.size(); ++i) {
                if(index_stack.empty() || heights[index_stack.top()] < heights[i]) {
                    index_stack.push(i);
                } else {
                    int temp = heights[index_stack.top()];
                    index_stack.pop();
                    int tempSum = 0;
                    if(index_stack.empty()) {
                        tempSum = temp * i;
                    } else {
                        tempSum = temp * (i - index_stack.top() - 1);
                    }
                    result = max(result, tempSum);
                    --i;
                }
            }
            heights.pop_back();
            return result;
        }
};

int main() {
    return 0;
}

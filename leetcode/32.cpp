#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        int longestValidParentheses(string s) {
            int N = s.length();
            if(N == 0) {
                return 0;
            }
            vector<int> pos_stack(N+1);
            int max = 0;
            int top = 0;
            pos_stack[0] = -1;
            for(int i=0; i<N; ++i) {
                int t = pos_stack[top];
                if((t != -1 && s[i] == ')') && s[t] == '(') {
                    int length = i - pos_stack[--top];
                    if(length > max) {
                        max = length;
                    }
                } else {
                    pos_stack[++top] = i;
                }
            }
            return max;
        }
};

int main() {
    Solution s;
    string str = ")))))";
    cout << s.longestValidParentheses(str) << endl;
    return 0;
}

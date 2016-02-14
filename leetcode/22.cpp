#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> result;
            generate(result, n, n, 0, "");
            return result;
        }
    private:
        void generate(vector<string>& result, int left, int right, int score, string curstr) {
            if(score < 0) {
                return;
            }
            if(left == 0 && right == 0) {
                result.push_back(curstr);
                return;
            }
            // (
            if(left > 0) {
                generate(result, left-1, right, score+1, curstr + "(");
            }
            if(right > 0) {
                generate(result, left, right-1, score-1, curstr + ")");
            }
        }
};


#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
        bool isMatch(string s, string p) {
            int star = -1;
            int s_star = 0;
            int i=0, k=0;
            int N = s.length();
            int M = p.length();

            while(i < s.length()) {
                if(i < N && k < M && (s[i] == p[k] || p[k] == '?')) {
                    ++i;
                    ++k;
                } else if(k < M && p[k] == '*') {
                    star = k;
                    s_star = i;
                    ++k;
                } else if(star != -1) {
                    k = star + 1;
                    ++s_star;
                    i = s_star;
                } else {
                    return false;
                }
            }
            while(k < M && p[k] == '*') {
                ++k;
            }

            return k == M;
        }
};

int main() {
    Solution s;
    cout << s.isMatch("aab", "c*a*b") << endl;
    return 0;
}

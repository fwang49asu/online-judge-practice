#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
    public:
        bool isScramble(string s1, string s2) {
            if(s1 == s2) {
                return true;
            }
            string a = s1;
            string b = s2;
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            if(a != b) {
                return false;
            }
            int n = s1.length();
            for(int i=1; i<n; ++i) {
                if(isScramble(s1.substr(0, i), s2.substr(0,i)) && isScramble(s1.substr(i, n - i), s2.substr(i, n - i))) {
                        return true;
                }
                if(isScramble(s1.substr(0, i), s2.substr(n - i, i)) && isScramble(s1.substr(i, n-i), s2.substr(0, n-i))) {
                    return true;
                }
            }
            return false;
        }
};

int main() {
    string s1 = "great";
    string s2 = "rgeat";
    Solution s;
    cout << s.isScramble(s1, s2) << endl;
    return 0;
}

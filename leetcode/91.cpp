#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int numDecodings(string s) {
            if(s.length() == 0 || s[0] == '0') {
                return 0;
            }
            if(s.length() == 1) {
                return 1;
            }
            int cache[2];
            cache[0] = 1;
            cache[1] = 1;
            for(int i=1; i<s.length(); ++i) {
                int code = (s[i-1] - '0') * 10 + s[i] - '0';
                if(s[i] == '0' && (s[i-1] == '0' || code > 26)) {
                    return 0;
                }
                int next = (s[i] == '0' ? 0 : cache[1]);
                next += ((s[i-1] != '0' && code <= 26) ? cache[0] : 0);
                cache[0] = cache[1];
                cache[1] = next;
            }
            return cache[1];
        }
};

int main() {
    string str = "101";
    Solution s;
    cout << s.numDecodings(str) << endl;
    return 0;
}

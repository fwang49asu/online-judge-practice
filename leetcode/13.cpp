#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int x = 0;
        for(int i=0; i<s.length(); ++i) {
            switch(s[i]) {
                case 'M':
                    x += 1000;
                    break;
                case 'D':
                    x += 500;
                    break;
                case 'L':
                    x += 50;
                    break;
                case 'V':
                    x += 5;
                    break;
                case 'C':
                    if(i<(s.length() - 1) && (s[i+1] == 'M' || s[i+1] == 'D')) {
                        x -= 100;
                    } else {
                        x += 100;
                    }
                    break;
                case 'X':
                    if(i<(s.length() - 1) && (s[i+1] == 'C' || s[i+1] == 'L')) {
                        x -= 10;
                    } else {
                        x += 10;
                    }
                    break;
                case 'I':
                    if(i<(s.length() - 1) && (s[i+1] == 'X' || s[i+1] == 'V')) {
                        --x;
                    } else {
                        ++x;
                    }
                    break;
            }
        }
        return x;
    }
};

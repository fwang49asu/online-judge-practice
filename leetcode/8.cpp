#include <string>
#include <limits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long long result = 0;
        int curpos = 0;
        for(; curpos < str.length() && str[curpos] == ' '; ++curpos);
        if(curpos == str.length() || !(str[curpos] == '+' || str[curpos] == '-' || (str[curpos] >= '0' && str[curpos] <= '9'))) {
            return 0;
        }
        bool neg = str[curpos] == '-';
        if(str[curpos] == '+' || str[curpos] == '-') {
            ++curpos;
        }
        for(; curpos < str.length() && str[curpos] >= '0' && str[curpos] <= '9'; ++curpos) {
            result = result * 10 + str[curpos] - '0';
            if(neg && (-result) < numeric_limits<int>::min()) {
                return numeric_limits<int>::min();
            }
            if((!neg) && result > numeric_limits<int>::max()) {
                return numeric_limits<int>::max();
            }
        }
        return neg ? (int)(-result) : (int)result;
    }
};

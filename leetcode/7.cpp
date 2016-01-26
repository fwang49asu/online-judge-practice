#include <limits>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long long y = x;
        bool neg = y < 0;
        if(neg) {
            y = -y;
        }
        long long result = 0;
        while(y > 0) {
            result = (result * 10) + (y % 10);
            y /= 10;
        }
        if(neg) {
            result = -result;
        }
        if(result > numeric_limits<int>::max() || result < numeric_limits<int>::min()) {
            result = 0;
        }
        return (int)result;
    }
};

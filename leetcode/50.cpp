#include <iostream>

using namespace std;

class Solution {
    public:
        double myPow(double x, int n) {
            if(n == 0) {
                return 1;
            }
            bool onemore = false;
            if(n < 0) {
                if(n == INT_MIN) {
                    n = INT_MAX;
                    onemore = true;
                } else {
                    n = -n;
                }
                x = 1/x;
            }
            int i=0;
            int curmask = 1;
            double curbuffer = x;
            double result = 1;
            for(; curmask <= n && i<32; ++i, curmask = (curmask << 1), curbuffer = curbuffer * curbuffer) {
                if(curmask & n) {
                    result *= curbuffer;
                }
            }
            if(onemore) {
                result *= x;
            }
            return result;
        }
};

int main() {
    Solution s;
    cout << s.myPow(8.88023, -3) << endl;
    return 0;
}

#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
    public:
        int divide(int dividend, int divisor) {
            int dividing_min = 0;
            if(dividend == 0) {
                return 0;
            }
            if(divisor == 0) {
                return INT_MAX;
            }
            if(divisor == dividend) {
                return 1;
            }
            if(dividend == INT_MIN) {
                if(divisor == -1) {
                    return INT_MAX;
                }
                dividing_min = 1;
                ++dividend;
            }
            if(divisor == INT_MIN) {
                return 0;
            }
            int sign = ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) ? 1 : -1;
            dividend = abs(dividend);
            divisor = abs(divisor);

            int num = 0;
            int sum = divisor;
            while(dividend - divisor + dividing_min >= 0) {
                sum = divisor;
                int t = 1;
                while(dividend - sum - sum + dividing_min >= 0) {
                    sum = (sum << 1);
                    t = (t << 1);
                }
                dividend -= sum;
                num += t;
            }
            return num * sign;
        }
};

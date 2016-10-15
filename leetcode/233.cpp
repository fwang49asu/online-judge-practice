class Solution {
public:
    int countDigitOne(int n) {
        long long result = 0;
        for(long long m = 1; m <= n; m *= 10) {
            long long a = n / m;
            long long b = n % m;
            result += (a+8) / 10 * m + (a%10 == 1) * (b+1);
        }
        return (int)result;
    }
};

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int uniquePaths(int m, int n) {
            --m;
            --n;
            // return C(m, m+n)
            if(m > n) {
                swap(m, n);
            }
            if(m == 0) {
                return 1;
            }
            int sum = m+n;
            long long upper = n+1;
            long long lower = 1;

            long long M = m;
            long long N = n;
            for(int i=0; i<M-1; ++i) {
                upper *= (sum - i);
                lower *= m-i;

                long long base = gcd(upper, lower);
                upper /= base;
                lower /= base;
            }
            return (int)upper;
        }

    private:
        long long gcd(long long a, long long b) {
            int d = 0;
            while((a&1)==0 && (b&1)==0) {
                a = a >> 1;
                b = b >> 1;
                ++d;
            }
            while(a != b) {
                if((a&1) == 0) {
                    a = a >> 1;
                } else if((b&1) == 0) {
                    b = b >> 1;
                } else if(a > b){
                    a = (a - b) >> 1;
                } else {
                    b = (b - a) >> 1;
                }
            }
            return a << d;
        }
};

int main() {
    Solution s;
    cout << s.uniquePaths(3, 7) << endl;
    return 0;
}

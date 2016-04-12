#include <iostream>
#include <climits>

using namespace std;

class Solution {
    public:
        int mySqrt(int x) {
            if(x < 0) {
                return INT_MIN;
            }
            if(x <= 1) {
                return x;
            }
            if(x == INT_MAX) {
                --x;
            }
            int length = 0;
            int mask = 1;
            while(mask > 0 && mask < x) {
                mask = mask << 1;
                ++length;
            }
            length = length >> 1;
            return (int)mySqrtBin(x, 1, 1 << (length+1));
        }
    private:
        long long mySqrtBin(long long x, long long low, long long high) {
            if(low > high) {
                return high;
            }
            int center = (low + high) >> 1;
            int mul = center * center;
            int higherMul = (center + 1) * (center+1);
            if(x == mul || (mul < x && higherMul > x)) {
                return center;
            }
            if(mul > x || mul <=0) {
                return mySqrtBin(x, low, center-1);
            }
            return mySqrtBin(x, center+1, high);
        }
};

int main() {
    Solution s;
    cout << s.mySqrt(2147483647) << endl;
    return 0;
}

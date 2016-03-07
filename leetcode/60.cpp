#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    public:
        string getPermutation(int n, int k) {
            string result = "";
            for(int i=1; i<=n; ++i) {
                result = result + (char)(i + '0');
            }
            int fact[10];
            fact[0] = 1;
            for(int i=1; i<n; ++i) {
                fact[i] = fact[i-1] * i;
            }
            --k;
            for(int i=n-1; i>0 && k>0; --i) {
                int x = k / fact[i];
                swap(result[n-1-i], result[n-1-i + x]);
                sort(result.begin() + n-i, result.end());
                k = k % fact[i];
            }
            return result;
        }
};

int main() {
    Solution s;
    cout << s.getPermutation(3, 6) << endl;
    return 0;
}

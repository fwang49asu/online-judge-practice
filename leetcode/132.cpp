#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        if(n == 0) {
            return 0;
        }
        vector<int> count(n+1, 0);
        for(int i=0; i<=n; ++i) {
            count[i] = i-1;
        }
        for(int i=0; i<n; ++i) {
            // odd
            for(int half_len = 0; (i-half_len) >= 0 && (i+half_len) < n && s[i-half_len] == s[i+half_len]; ++half_len) {
                // update
                count[i+half_len+1] = min(count[i+half_len+1], 1+count[i-half_len]);
            }
            // even
            for(int half_len = 1; (i-half_len+1) >= 0 && (i+half_len) < n && s[i-half_len+1] == s[i+half_len]; ++half_len) {
                count[i+half_len+1] = min(count[i+half_len+1], 1+count[i-half_len+1]);
            }
        }
        return count[n];
    }
};

int main() {
}

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int minDistance(string word1, string word2) {
            string s = word1;
            string t = word2;
            int n = s.length();
            int m = t.length();
            if(n > m) {
                swap(n, m);
                s.swap(t);
            }
            int** d = new int*[n+1];
            for(int i=0; i<=n; ++i) {
                d[i] = new int[m+1];
            }

            for(int i=0; i<=n; ++i) {
                d[i][0] = i;
            }
            for(int i=0; i<=m; ++i) {
                d[0][i] = i;
            }

            for(int i=1; i<=n; ++i) {
                for(int k=1; k<=m; ++k) {
                    if(s[i-1] == t[k-1]) {
                        d[i][k] = d[i-1][k-1];
                    } else {
                        d[i][k] = min(d[i-1][k] + 1, d[i][k-1] + 1);
                        d[i][k] = min(d[i][k], d[i-1][k-1] + 1);
                    }
                }
            }
            int result = d[n][m];

            for(int i=0; i<=n; ++i) {
                delete[] d[i];
            }
            delete[] d;
            return result;
        }
};

int main() {
    return 0;
}

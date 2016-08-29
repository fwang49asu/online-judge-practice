#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> buffer;
        buffer.push_back(1);
        for(int i=1; i<=n; ++i) {
            int t = 0;
            for(int k=1; k<=i; ++k) {
                t += buffer[k-1] * buffer[i-k];
            }
            buffer.push_back(t);
        }
        return buffer[n];
    }
};

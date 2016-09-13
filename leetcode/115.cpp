#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int* buffer = new int[t.length() + 1];
        // empty string: only one setting
        buffer[0] = 1;
        for(int i=1; i<=t.length(); ++i) {
            buffer[i] = 0;
        }
        for(int i=0; i<s.length(); ++i) {
            for(int k=t.length()-1; k>=0; --k) {
                if(s[i] == t[k]) {
                    buffer[k+1] += buffer[k];
                }
            }
        }
        int result = buffer[t.length()];
        delete[] buffer;
        return result;
    }
};

int main() {
    Solution s;
    cout << s.numDistinct("b", "b") << endl;
    return 0;
}

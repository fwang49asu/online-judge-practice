#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.length() == t.length()) {
            int n = s.length();
            bool diff = false;
            for(int i=0; i<n; ++i) {
                if(s[i] != t[i]) {
                    if(diff) {
                        return false;
                    } else {
                        diff = true;
                    }
                }
            }
            return diff;
        }
        if(s.length() > t.length()) {
            return isOneEditDistance(t, s);
        }
        if((t.length() - s.length()) != 1) {
            return false;
        }
        // check whether insert character into s and become t
        int n = s.length();
        int a = 0;
        int b = 0;
        while(a<n && (b-a) <=1) {
            if(s[a] != t[b]) {
                ++b;
            } else {
                ++a;
                ++b;
            }
        }
        
        int diff = b-a;
        if(diff == 0) {
            return true;
        }
        if(diff > 1) {
            return false;
        }
        return t[n] == s[n-1];
    }
};

int main() {
    Solution s;
    cout << s.isOneEditDistance("ab", "acd") << endl;
    return 0;
}

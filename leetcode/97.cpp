#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            string a = s1;
            string b = s2;
            string c = s3;
            if((a.length() + b.length()) != s3.length()) {
                return false;
            }
            if(s1.length() == 0) {
                return s2 == s3;            
            }
            if(s2.length() == 0) {
                return s1 == s3;
            }
            string d = a+b;
            sort(c.begin(), c.end());
            sort(d.begin(), d.end());
            if(c != d) {
                return false;
            }

            unordered_set<int> configSet;
            if(s1.length() >= s2.length()) {
                return isInterleave(s1, 0, s2, 0, s3, configSet);
            }
            return isInterleave(s2, 0, s1, 0, s3, configSet);
        }

    private:
        bool isInterleave(string s1, int i, string s2, int k, string s3, unordered_set<int>& configSet) {
            // should we continue?
            int n = s1.length();
            int m = s2.length();
            if(i == n && k == m) {
                return true;
            }
            int hash = (i * (n+1)) + k;
            if(configSet.find(hash) != configSet.end()) {
                return false;
            }
            if(i < n && s1[i] == s3[i+k] && isInterleave(s1, i+1, s2, k, s3, configSet)) {
                return true;
            }
            if(k < m && s2[k] == s3[i+k] && isInterleave(s1, i, s2, k+1, s3, configSet)) {
                return true;
            }
            configSet.insert(hash);
            return false;
        }
};

int main() {
    Solution s;
    cout << s.isInterleave("aabc", "abad", "abadaabc") << endl;
    return 0;
}

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int length = s.length();
        if(length == 0 || wordDict.empty()) {
            return false;
        }
        vector<bool> result = vector<bool>(length + 1, false);
        result[0] = true;
        for(int i=1; i<=length; ++i) {
            for(int k=0; k<i; ++k) {
                if(result[k] && wordDict.find(s.substr(k, i-k)) != wordDict.end()) {
                    result[i] = true;
                    break;
                }
            }
        }
        return result[length];
    }
};

int main() {
    unordered_set<string> dic;
    dic.insert("leet");
    dic.insert("code");
    Solution s;
    cout << s.wordBreak("leetcode", dic);
    return 0;
}

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        vector<string> restoreIpAddresses(string s) {
            vector<string> result;
            int n = s.length();
            int dotPos[3];
            string parts[4];
            for(dotPos[0]=1; dotPos[0]<=3; ++dotPos[0]) {
                // first one valid?
                parts[0] = s.substr(0, dotPos[0]);
                if(!valid(parts[0])) {
                    continue;
                }
                for(dotPos[1] = dotPos[0]+1; dotPos[1] < (n-1) && dotPos[1] <= (dotPos[0] + 3); ++dotPos[1]) {
                    parts[1] = s.substr(dotPos[0], dotPos[1] - dotPos[0]);
                    if(!valid(parts[1])) {
                        continue;
                    }
                    for(dotPos[2] = dotPos[1]+1; dotPos[2] < n && dotPos[2] <= (dotPos[1] + 3); ++dotPos[2]) {
                        parts[2] = s.substr(dotPos[1], dotPos[2] - dotPos[1]);
                        if(!valid(parts[2])) {
                            continue;
                        }
                        parts[3] = s.substr(dotPos[2], n - dotPos[2]);
                        if(!valid(parts[3])) {
                            continue;
                        }
                        string x = parts[0] + '.' + parts[1] + '.' + parts[2] + '.' + parts[3];
                        result.push_back(x);
                    }
                }
            }
            return result;
        }
        bool valid(string& s) {
            if(s.length() == 1) {
                return true;
            }
            if(s[0] == '0') {
                return false;
            }
            if(s.length() > 3) {
                return false;
            }
            int code = 0;
            for(int i=0; i<s.length(); ++i) {
                code = code * 10 + s[i] - '0';
            }
            return code <= 255;
        }
};

int main() {
    Solution s;
    vector<string> vec = s.restoreIpAddresses("2736786374048");
    for(string str: vec) {
        cout << str << endl;
    }
    return 0;
}

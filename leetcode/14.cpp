#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        if(strs.size() == 0) {
            return result;
        }
        for(int i=0; i < strs[0].length(); ++i) {
            char c = strs[0][i];
            for(string str: strs) {
                if(i >= str.length() || str[i] != c) {
                    return result;
                }
            }
            result = result + c;
        }
        return result;
    }
};

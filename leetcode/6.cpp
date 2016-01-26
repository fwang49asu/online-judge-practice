#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.length()) {
            return s;
        }
        string result = s;
        int diagnal = numRows - 2;
        int unit = numRows + diagnal;
        // first
        int pos = 0;
        for(int i=0; i<s.length(); i+=unit) {
            result[pos] = s[i];
            ++pos;
        }
        for(int row=1; row<numRows-1; ++row) {
            for(int i=row; i<s.length(); i+=unit) {
                result[pos] = s[i];
                ++pos;
                int nextIndex = (i/unit + 1) * unit - row;
                if(nextIndex < s.length()) {
                    result[pos] = s[nextIndex];
                    ++pos;
                }
            }
        }
        for(int i=numRows-1; i<s.length(); i+=unit) {
            result[pos] = s[i];
            ++pos;
        }
        return result;
    }
};

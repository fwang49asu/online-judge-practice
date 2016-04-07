#include <string>
#include <iostream>

using namespace std;

class Solution {
    public:
        bool isNumber(string s) {
            int length = s.length();
            // skip the spaces
            if(s[0] == ' ' || s[length - 1] == ' ') {
                int start;
                int end;
                for(start = 0; start<length && s[start] == ' '; ++start) ;
                for(end = length - 1; end >= start && s[end] == ' '; --end) ;
                return isNumber(s.substr(start, end - start+1));
            }
            // find the e for scientific format
            int epos = s.find('e');
            if(epos == -1) {
                return isInteger(s) || isFloat(s);
            } else {
                string front = s.substr(0, epos);
                string end = s.substr(epos+1, length);
                return isInteger(end) && (isInteger(front) || isFloat(front));
            }
        }
    private:
        bool isInteger(string s) {
            int length = s.length();
            if(s[0] == '+' || s[0] == '-') {
                return isIntegerWithoutSign(s.substr(1, length - 1));
            }
            return isIntegerWithoutSign(s);
        }
        bool isIntegerWithoutSign(string s) {
            int length = s.length();
            if(length == 0) {
                return false;
            }
            for(int i=0; i<length; ++i) {
                if(s[i] < '0' || s[i] > '9') {
                    return false;
                }
            }
            return true;
        }
        bool isFloat(string s) {
            int length = s.length();
            if(s[0] == '+' || s[0] == '-') {
                return isFloatWithoutSign(s.substr(1, length - 1));
            }
            return isFloatWithoutSign(s);
        }
        bool isFloatWithoutSign(string s) {
            int length = s.length();
            int dotpos = s.find('.');
            if(dotpos == -1) {
                return false;
            }
            if(dotpos == 0) {
                return isIntegerWithoutSign(s.substr(1, length - 1));
            }
            if(dotpos == (length - 1)) {
                return isIntegerWithoutSign(s.substr(0, length - 1));
            }
            string front = s.substr(0, dotpos);
            string end = s.substr(dotpos+1, length);
            return isIntegerWithoutSign(front) && isIntegerWithoutSign(end);
        }
};

int main() {
    Solution s;
    cout << s.isNumber("1 ") << endl;
    return 0;
}

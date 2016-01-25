#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "") {
            return "";
        }
        int maxlength = 1;
        int minstart = 0;
        for(int i=0; i<s.length();) {
            int low = i;
            int high = low + 1;
            while(s[low] == s[high]) {
                ++high;
            }
            int next = high;
            --high;
            while(low >=0 && high < s.length() && s[low] == s[high]) {
                int length = high - low + 1;
                if(length > maxlength) {
                    maxlength = length;
                    minstart = low;
                }
                --low;
                ++high;
            }
            i = next;
        }
        return s.substr(minstart, maxlength);
    }

};

#include <string>
#include <iostream>

using namespace std;

class Solution {
    public:
        int strStr(string haystack, string needle) {
            if(needle.length() == 0) {
                return 0;
            }
            if(haystack.length() < needle.length()) {
                return -1;
            }
            if(needle.length() == 1) {
                for(int i=0; i<haystack.size(); ++i) {
                    if(haystack[i] == needle[0]) {
                        return i;
                    }
                }
                return -1;
            }
            int* T = new int[needle.length()];
            kmp_table(needle, T);
            int m, i;
            m = 0;
            i = 0;
            while((m+i) < haystack.length()) {
                if(needle[i] == haystack[m+i]) {
                    if(i==(needle.length() - 1)) {
                        delete[] T;
                        return m;
                    }
                    ++i;
                } else {
                    if(T[i] > 0) {
                        m = m + i - T[i];
                        i = T[i];
                    } else {
                        i = 0;
                        ++m;
                    }
                }
            }
            delete[] T;
            return -1;
        }
    private:
        void kmp_table(string& W, int* T) {
            int pos = 2;
            int cur = 0;
            T[0] = -1;
            T[1] = 0;
            while(pos < W.length()) {
                if(W[pos-1] == W[cur]) {
                    T[pos] = cur+1;
                    ++cur;
                    ++pos;
                } else if(cur > 0) {
                    cur = T[cur];
                } else {
                    T[pos] = 0;
                    cur = 0;
                    ++pos;
                }
            }
        }
};

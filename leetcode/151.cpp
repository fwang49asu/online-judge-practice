#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        // remove the redundant spaces
        {
            int size = 0;
            int space = 1;
            for(int i=0; i<s.length(); ++i) {
                if(s[i] == ' ') {
                    if(space == 0) {
                        s[size++] = s[i];
                        ++space;
                    }
                } else {
                    space = 0;
                    s[size++] = s[i];
                }
            }
            if(space == 1) {
                --size;
            }
            size = max(size, 0);
            s.resize(size);
        }
        reverseStringSeg(s, 0, s.length()-1);
        int prev = 0;
        for(int i=0; i<s.length(); ++i) {
            if(s[i] == ' ') {
                reverseStringSeg(s, prev, i-1);
                prev = i+1;
            }
        }
        reverseStringSeg(s, prev, s.length() - 1);
    }
private:
    void reverseStringSeg(string& s, int low, int high) {
        for(; low < high; ++low, --high) {
            swap(s[low], s[high]);
        }
    }
};

int main() {
    string str = "   the  sky is blue   ";
    Solution s;
    s.reverseWords(str);
    cout << "\"" << str << "\"" << endl;
    return 0;
}

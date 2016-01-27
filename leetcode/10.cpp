#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        State* pattern = new State[p.length() + 1];
        int patternLength = 0;
        for(int i=0; i<p.length(); ++i) {
            if(p[i] == '*') {
                pattern[patternLength - 1].star = true;
            } else {
                pattern[patternLength].c = p[i];
                pattern[patternLength].star = false;
                ++patternLength;
            }
        }
        pattern[patternLength].c = '$';
        pattern[patternLength].star = false;
        bool* enabled = new bool[patternLength + 1];
        bool* back = new bool[patternLength + 1];
        for(int i=0; i<=patternLength; ++i) {
            enabled[i] = false;
            back[i] = false;
        }
        // initialize
        enabled[0] = true;
        for(int i=0; i<patternLength && pattern[i].star; ++i) {
            if(pattern[i].star) {
                enabled[i+1] = true;
            }
        }
        for(int i=0; i<s.length(); ++i) {
            for(int k=0; k<patternLength; ++k) {
                if(enabled[k]) {
                    if(pattern[k].c == '.' || pattern[k].c == s[i]) {
                        back[k+1] = true;
                        if(pattern[k].star) {
                            back[k] = true;
                        }
                    }
                }
            }
            for(int k=0; k<patternLength; ++k) {
                if(back[k]) {
                    for(int x=k; x<patternLength && pattern[x].star; ++x) {
                        back[x+1] = true;
                    }
                }
            }
            for(int k=0; k<=patternLength; ++k) {
                enabled[k] = false;
            }
            swap(enabled, back);
        }
        bool result = enabled[patternLength];
        delete[] back;
        delete[] enabled;
        delete[] pattern;
        return result;;
    }
private:
    struct State{
        char c;
        bool star;
    };
};

int main() {
    Solution s;
    std::cout << s.isMatch("aa", "a*") << std::endl;
    return 0;
}

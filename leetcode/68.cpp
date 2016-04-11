#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            int i=0;
            vector<string> result;
            int index = 0;
            vector<int> vec;
            vector<int> length;
            for(int i=0; i<words.size(); ++i) {
                length.push_back(words[i].length());
            }
            while(index < words.size()) {
                // try to fill the line
                int remaining = maxWidth;
                int sumLength = 0;
                vec.clear();
                while(index < words.size() && remaining >= length[index]) {
                    vec.push_back(index);
                    sumLength += length[index];
                    remaining -= (length[index] + 1);
                    ++index;
                }
                if(index == words.size() || vec.size() == 1) {
                    // last line or only one word
                    string str = words[vec[0]];
                    for(int i=1; i<vec.size(); ++i) {
                        str += " ";
                        str += words[vec[i]];
                    }
                    sumLength = maxWidth - sumLength - vec.size() + 1;
                    for(int i=0; i<sumLength; ++i) {
                        str += " ";
                    }
                    result.push_back(str);
                } else {
                    // evenly justify
                    sumLength = maxWidth - sumLength;
                    int smallSpace = sumLength / (vec.size() - 1);
                    int leftCount = sumLength % (vec.size() - 1);
                    int i;
                    string str = words[vec[0]];
                    for(i=0; i<leftCount; ++i) {
                        for(int k=0; k<=smallSpace; ++k) {
                            str += " ";
                        }
                        str += words[vec[i+1]];
                    }
                    for(; i<vec.size() - 1; ++i) {
                        for(int k=0; k<smallSpace; ++k) {
                            str += " ";
                        }
                        str += words[vec[i+1]];
                    }
                    result.push_back(str);
                }
            }
            return result;
        }
};

int main() {
    vector<string> vec;
    string str;
    while(cin >> str) {
        vec.push_back(str);
    }
    Solution s;
    vector<string> result = s.fullJustify(vec, 16);
    for(string x : result) {
        cout << "\"" << x << "\"" << endl;
    }
    return 0;
}

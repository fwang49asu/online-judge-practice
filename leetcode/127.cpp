#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        // bfs
        unordered_set<string> used_set;
        vector<string> working_vec;
        vector<string> next_vec;
        int len = beginWord.length();
        if(beginWord.length() != endWord.length() || beginWord.compare(endWord) == 0) {
            return 0;
        }
        working_vec.push_back(beginWord);
        int result = 1;
        while(!working_vec.empty()) {
            ++result;
            for(string& s: working_vec) {
                for(int i=0; i<len; ++i) {
                    string t = s;
                    for(char c='a'; c<='z'; ++c) {
                        if(c == s[i]) {
                            continue;
                        }
                        t[i] = c;
                        if(endWord.compare(t) == 0) {
                            return result;
                        }
                        if(used_set.find(t) == used_set.end() && wordList.find(t) != wordList.end()) {
                            next_vec.push_back(t);
                            used_set.insert(t);
                            t = s;
                        }
                    }
                }
            }
            vector<string> vec;
            working_vec.swap(next_vec);
            next_vec.swap(vec);
        }
        return 0;
    }
};

int main(int argc, char const *argv[]) {
    string array[] = {"hot","dot","dog","lot","log"};
    unordered_set<string> data_set(array, array + 5);
    string begin = "hit";
    string end = "cog";
    Solution s;
    cout << s.ladderLength(begin, end, data_set) << endl;
    return 0;
}

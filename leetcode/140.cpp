#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int length = s.length();
        vector<string> result;
        if(length == 0 || wordDict.empty()) {

            return result;
        }
        min_word_length = INT_MAX;
        max_word_length = 0;
        for(string x: wordDict) {
            int len = x.length();
            min_word_length = min(min_word_length, len);
            max_word_length = max(max_word_length, len);
        }
        step_ahead(s, 0, wordDict);
        if(solution_map.find(0) != solution_map.end()) {
            result = solution_map[0];
        }
        return result;
    }
private:
    int min_word_length;
    int max_word_length;
    unordered_set<int> failed_set;
    unordered_map<int, vector<string>> solution_map;
    // we use the start to omit the substr operation
    bool step_ahead(string s, int start, unordered_set<string>& word_dic) {
        int length = s.length();
        if(length == start || solution_map.find(start) != solution_map.end()) {
            return true;
        }
        if(failed_set.find(start) != failed_set.end()) {
            return false;
        }

        vector<string> result;
        for(int i=min_word_length; i <= max_word_length && (i+start) <= length; ++i) {
            // try this word
            string word = s.substr(start, i);
            if(word_dic.find(word) != word_dic.end() && step_ahead(s, start + i, word_dic)) {
                // last one?
                if((start+i) == length) {
                    result.push_back(word);
                } else {
                    auto vec = solution_map[start + i];
                    for(string x: vec) {
                        result.push_back(word + " " + x);
                    }
                }
            }
        }

        if(result.empty()) {
            failed_set.insert(start);
            return false;
        }
        solution_map[start] = result;
        return true;
    }
};


int main() {
    unordered_set<string> dic;
    dic.insert("leet");
    dic.insert("code");
    Solution s;
    vector<string> result = s.wordBreak("leetcode", dic);
    for(string str: result) {
        cout << str << endl;
    }
    return 0;
}

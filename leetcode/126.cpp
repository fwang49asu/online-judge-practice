#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        wordList.erase(beginWord);
        wordList.erase(endWord);
        vector<vector<string>> result;
        if(beginWord == endWord) {
            vector<string> vec;
            vec.push_back(beginWord);
            vec.push_back(endWord);
            result.push_back(vec);
            return result;
        }
        int len = beginWord.length();
        unordered_map<string, vector<string>> left_used_map;
        unordered_map<string, vector<string>> right_used_map;
        unordered_set<string> left_set;
        unordered_set<string> next_set;
        unordered_set<string> right_set;

        string begin = beginWord;
        string end = endWord;

        left_set.insert(begin);
        right_set.insert(end);
        bool flip = false;

        while(!left_set.empty()) {
            // we can assume that there are no overlap between left and right
            unordered_set<string> matched_set;
            unordered_map<string, vector<string>> tmp_map;
            for(string s: left_set) {
                for(int i=0; i<len; i++) {
                    for(char c = 'a'; c<='z'; ++c) {
                        if(c == s[i]) {
                            continue;
                        }
                        string t = s;
                        t[i] = c;

                        if(right_set.find(t) != right_set.end()) {
                            matched_set.insert(t);
                            if(left_used_map.find(t) == left_used_map.end()) {
                                vector<string> vec;
                                left_used_map.insert(make_pair(t, vec));
                            }
                            left_used_map[t].push_back(s);
                        } else if(wordList.find(t) != wordList.end() && left_used_map.find(t) == left_used_map.end()) {
                            if(left_used_map.find(t) == left_used_map.end()) {
                                vector<string> vec;
                                tmp_map.insert(make_pair(t, vec));
                            }
                            tmp_map[t].push_back(s);

                            next_set.insert(t);
                            t = s;
                        }
                    }
                }
            }
            for(auto e: tmp_map) {
                left_used_map.insert(e);
            }
            if(!matched_set.empty()) {
                // found it!
                vector<vector<string>> left_vec;
                vector<vector<string>> right_vec;
                // construct the left side
                for(string s: matched_set) {
                    vector<string> buffer;
                    BuildPath(s, left_used_map, buffer, left_vec);
                }
                // construct the right side
                for(string s: matched_set) {
                    vector<string> buffer;
                    BuildPath(s, right_used_map, buffer, right_vec);
                }

                for(vector<string>& left: left_vec) {
                    for(vector<string>& right: right_vec) {
                        if(left[0] != right[0]) {
                            continue;
                        }
                        vector<string> vec;
                        if(flip) {
                            for(int i=right.size() - 1; i>=0; --i) {
                                vec.push_back(right[i]);
                            }
                            for(int i=1; i<left.size(); ++i) {
                                vec.push_back(left[i]);
                            }
                        } else {
                            for(int i=left.size() - 1; i>=0; --i) {
                                vec.push_back(left[i]);
                            }
                            for(int i=1; i<right.size(); ++i) {
                                vec.push_back(right[i]);
                            }
                        }
                        result.push_back(vec);
                    }
                }
                return result;
            }
            if(next_set.empty()) {
                return result;
            }
            left_set.swap(next_set);
            unordered_set<string> empty_set;
            next_set.swap(empty_set);

            if(left_set.size() > right_set.size()) {
                flip = !flip;
                left_set.swap(right_set);
                left_used_map.swap(right_used_map);
            }
        }
        return result;
    }
private:
    void BuildPath(string& cur, unordered_map<string, vector<string>>& used_map, vector<string>& buffer, vector<vector<string>>& result) {
        if(used_map.find(cur) == used_map.end()) {
            vector<string> vec(buffer);
            vec.push_back(cur);
            result.push_back(vec);
            return;
        }
        buffer.push_back(cur);
        vector<string>& next = used_map[cur];
        for(string s: next) {
            BuildPath(s, used_map, buffer, result);
        }
        buffer.pop_back();
    }
};

int main(int argc, char const *argv[]) {
    string array[] = {"flail","halon","lexus","joint","pears","slabs","lorie","lapse","wroth","yalow","swear","cavil","piety","yogis","dhaka","laxer","tatum","provo","truss","tends","deana","dried","hutch","basho","flyby","miler","fries","floes","lingo","wider","scary","marks","perry","igloo","melts","lanny","satan","foamy","perks","denim","plugs","cloak","cyril","women","issue","rocky","marry","trash","merry","topic","hicks","dicky","prado","casio","lapel","diane","serer","paige","parry","elope","balds","dated","copra","earth","marty","slake","balms","daryl","loves","civet","sweat","daley","touch","maria","dacca","muggy","chore","felix","ogled","acids","terse","cults","darla","snubs","boats","recta","cohan","purse","joist","grosz","sheri","steam","manic","luisa","gluts","spits","boxer","abner","cooke","scowl","kenya","hasps","roger","edwin","black","terns","folks","demur","dingo","party","brian","numbs","forgo","gunny","waled","bucks","titan","ruffs","pizza","ravel","poole","suits","stoic","segre","white","lemur","belts","scums","parks","gusts","ozark","umped","heard","lorna","emile","orbit","onset","cruet","amiss","fumed","gelds","italy","rakes","loxed","kilts","mania","tombs","gaped","merge","molar","smith","tangs","misty","wefts","yawns","smile","scuff","width","paris","coded","sodom","shits","benny","pudgy","mayer","peary","curve","tulsa","ramos","thick","dogie","gourd","strop","ahmad","clove","tract","calyx","maris","wants","lipid","pearl","maybe","banjo","south","blend","diana","lanai","waged","shari","magic","duchy","decca","wried","maine","nutty","turns","satyr","holds","finks","twits","peaks","teems","peace","melon","czars","robby","tabby","shove","minty","marta","dregs","lacks","casts","aruba","stall","nurse","jewry","knuth"};
    unordered_set<string> data_set(array, array + 218);
    string begin = "magic";
    string end = "pearl";
    Solution s;
    vector<vector<string>> vec = s.findLadders(begin, end, data_set);
    for(auto v: vec) {
        for(auto s: v) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}

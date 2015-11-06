#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    bool wordPattern(string pattern, string str) {
      if(pattern.length() == 0 && str.length() == 0) {
        return true;
      }
      vector<string> vec;
      string s = str;
      while(s.length() > 0) {
        int index = 0;
        for(; index < s.length() && s[index] != ' '; ++index);
        vec.push_back(s.substr(0, index));
        if(index == s.length()) {
          s = "";
        } else {
          s = s.substr(index+1);
        }
      }
      if(pattern.length() != vec.size()) {
        return false;
      }
      int n = pattern.length();
      unordered_map<char, string> forwardMap;
      unordered_map<string, char> backwardMap;
      for(int i=0; i<n; ++i) {
        char c = pattern[i];
        s = vec[i];
        if(forwardMap.find(c) == forwardMap.end()) {
          forwardMap[c] = s;
        } else {
          if(forwardMap[c].compare(s) != 0) {
            return false;
          }
        }
        if(backwardMap.find(s) == backwardMap.end()) {
          backwardMap[s] = c;
        } else {
          if(backwardMap[s] != c) {
            return false;
          }
        }
      }
      return true;
    }
};
int main() {
  string pattern = "abba";
  string str = "dog cat cat dog";
  Solution s;
  cout << s.wordPattern(pattern, str) << endl;
  return 0;
}

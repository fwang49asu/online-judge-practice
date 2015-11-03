#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      unordered_map<char, int> index_map;
      if(s.length() == 0) {
        return 0;
      }
      int result = 1;
      int start = 0;
      index_map.insert(make_pair(s[0], 0));
      for(int end = 1; end < s.length(); ++end) {
        char c = s[end];
        if(index_map.find(c) != index_map.end()) {
          start = max(start, index_map[c]+1);
        }
        result = max(result, end - start + 1);
        index_map[c] = end;
      }
      return result;
    }
};

int main() {
  string str;
  cin >> str;
  Solution s;
  cout << s.lengthOfLongestSubstring(str) << endl;
  return 0;
}

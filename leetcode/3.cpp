#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int result = 1;
        int start = 0;
        if(s.length() == 0) {
            return 0;
        }
        map<char, int> index_map;
        index_map[s[0]] = 0;
        for(int end = 1; end < s.length(); ++end) {
            char c = s[end];
            if(index_map.end() != index_map.find(c)) {
                start = max(start, index_map[c]+1);
            }
            index_map[c] = end;
            result = max(result, end-start+1);
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

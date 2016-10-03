#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        if(n <= 2) {
            return n;
        }
        unordered_map<char, int> count_map;
        AddOne(count_map, s[0]);
        AddOne(count_map, s[1]);

        int result = 2;
        int low = 0;
        for(int i=2; i<n; ++i) {
            AddOne(count_map, s[i]);
            while(count_map.size() > 2) {
                MinusOne(count_map, s[low++]);
            }
            result = max(result, i - low + 1);
        }
        return result;
    }
private:
    void AddOne(unordered_map<char, int>& m, char c) {
        if(m.find(c) == m.end()) {
            m.insert(make_pair(c, 1));
        } else {
            ++m[c];
        }
    }
    void MinusOne(unordered_map<char, int>& m, char c) {
        --m[c];
        if(m[c] == 0) {
            m.erase(c);
        }
    }
};

int main() {
    return 0;
}

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        string minWindow(string s, string t) {
            int n = s.length();
            int m = t.length();
            unordered_map<char, int> targetMap;
            unordered_map<char, int> countMap;
            for(int i=0; i<m; ++i) {
                addCount(targetMap, t[i]);
            }
            int countTotal = 0;
            string result = "";
            int low, high;
            low = 0;
            high = 0;
            for(; high < n && countTotal < m; ++high) {
                char c = s[high];
                if(targetMap.find(c) == targetMap.end()) {
                    continue;
                }
                addCount(countMap, c);
                if(countMap[c] <= targetMap[c]) {
                    ++countTotal;
                }
            }
            if(countTotal < m) {
                return "";
            }
            shrink(s, t, targetMap, countMap, countTotal, low, high, m);
            result = s.substr(low, high - low);
            minusCount(countMap, s[low]);
            --countTotal;
            ++low;
            for(; high < n; ++high, ++low) {
                if(countTotal == m) {
                    shrink(s, t, targetMap, countMap, countTotal, low, high, m);
                    result = s.substr(low, high - low);
                    minusCount(countMap, s[low]);
                    --countTotal;
                    ++low;
                }
                minusCount(countMap, s[low]);
                if(getCount(countMap, s[low]) < targetMap[s[low]]) {
                    --countTotal;
                }
                addCount(countMap, s[high]);
                if(countMap[s[high]] <= targetMap[s[high]]) {
                    ++countTotal;
                }
            }
            if(countTotal == m) {
                shrink(s, t, targetMap, countMap, countTotal, low, high, m);
                return s.substr(low, high - low);
            }
            return result;
        }
    private:
        void shrink(string& s, string& t, unordered_map<char, int>& targetMap,
                unordered_map<char, int>& countMap, int& countTotal, int& low, int& high, int m) {
            for(; low < high && countTotal == m; ++low) {
                char c = s[low];
                if(targetMap.find(c) == targetMap.end()) {
                    continue;
                }
                minusCount(countMap, c);
                if(getCount(countMap, c) < targetMap[c]) {
                    --countTotal;
                }
            }
            --low;
            ++countTotal;
            addCount(countMap, s[low]);
        }
        int getCount(unordered_map<char, int>& countMap, char c) {
            if(countMap.find(c) == countMap.end()) {
                return 0;
            }
            return countMap[c];
        }
        void addCount(unordered_map<char, int>& countMap, char c) {
            if(countMap.find(c) == countMap.end()) {
                countMap[c] = 1;
                return;
            }
            ++countMap[c];
        }
        void minusCount(unordered_map<char, int>& countMap, char c) {
            if(countMap.find(c) == countMap.end()) {
                return;
            }
            int count = countMap[c];
            --count;
            if(count == 0) {
                countMap.erase(c);
                return;
            }
            countMap[c] = count;
        }
};

int main() {
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}

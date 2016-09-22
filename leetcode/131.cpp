#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> buffer;
        unordered_map<int, bool> test_cache;
        int len = s.length();
        dfs(s, len, 0, buffer, test_cache, result);
        return result;
    }
private:
    void dfs(string& s, int len, int low, vector<string>& buffer, unordered_map<int, bool>& test_cache, vector<vector<string>>& result) {
        if(low == len) {
            result.push_back(buffer);
            return;
        }
        int base = low * len;
        for(int i=low; i<len; ++i) {
            int key = base + i;
            bool is_palindome = false;
            if(test_cache.find(key) == test_cache.end()) {
                test_cache[key] = test(s, low, i);
            }
            is_palindome = test_cache[key];
            if(!is_palindome) {
                continue;
            }
            buffer.push_back(s.substr(low, i-low+1));
            dfs(s, len, i+1, buffer, test_cache, result);
            buffer.pop_back();
        }
    }
private:
    bool test(string& s, int low, int high) {
        while(low < high) {
            if(s[low] != s[high]) {
                return false;
            }
            ++low;
            --high;
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    return 0;
}

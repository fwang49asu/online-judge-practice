#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        vector<vector<string> > groupAnagrams(vector<string>& strs) {
            vector<vector<string> > result;
            unordered_map<string, int> index_map;
            for(int i=0; i<strs.size(); ++i) {
                string str = strs[i];
                sort(str.begin(), str.end());
                int index = 0;
                if(index_map.find(str) == index_map.end()) {
                    index = index_map.size();
                    index_map[str] = index;
                    vector<string> vec;
                    result.push_back(vec);
                } else {
                    index = index_map[str];
                }
                result[index].push_back(strs[i]);
            }
            for(int i=0; i<result.size(); ++i) {
                sort(result[i].begin(), result[i].end());
            }
            return result;
        }
};

int main() {
    string data[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> vec(data, data+6);
    Solution s;
    vector<vector<string> > result = s.groupAnagrams(vec);
    for(auto v: result) {
        for(string str : v) {
            cout << str << "\t";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

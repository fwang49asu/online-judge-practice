#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> result;

        vector<pair<int, int>> corner_vec;
        for(auto v: buildings) {
            corner_vec.push_back(make_pair(v[0], -v[2]));
            corner_vec.push_back(make_pair(v[1], v[2]));
        }
        sort(corner_vec.begin(), corner_vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
            if(a.first != b.first) {
                return a.first < b.first;
            }
            return a.second < b.second;
        });
        // initial 0
        multiset<int> heights;
        heights.insert(0);
        int prev = 0;
        for(auto p : corner_vec) {
            if(p.second < 0) {
                // left
                heights.insert(-p.second);
            } else {
                // right
                heights.erase(heights.find(p.second));
            }
            // get the largest
            set<int>::iterator it = heights.end();
            --it;
            int top = *it;
            if(top != prev) {
                result.push_back(make_pair(p.first, top));
                prev = top;
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> buildings;
    int a;
    int b;
    int c;
    while(cin >> a >> b >> c) {
        vector<int> vec;
        vec.push_back(a);
        vec.push_back(b);
        vec.push_back(c);
        buildings.push_back(vec);
    }
    Solution s;
    vector<pair<int, int>> result = s.getSkyline(buildings);
    for(auto p: result) {
        cout << p.first << "\t" << p.second << endl;
    }
    return 0;
}

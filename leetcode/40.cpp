#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
            vector<vector<int> > result;
            map<int, int> candidate_map;
            for(int x: candidates) {
                if(candidate_map.find(x) == candidate_map.end()) {
                    candidate_map[x] = 1;
                } else {
                    int count = candidate_map[x];
                    candidate_map[x] = count+1;
                }
            }
            vector<pair<int, int> > my_stack;
            combinationSum2(candidate_map, target, my_stack, result);
            return result;
        }
    private:
        void combinationSum2(map<int, int>& candidate_map, int target, vector<pair<int, int> >& my_stack, vector<vector<int> >& result) {
            if(target < 0) {
                return;
            }
            if(target == 0) {
                vector<int> vec;
                for(auto p : my_stack) {
                    for(int i=0; i<p.second; ++i) {
                        vec.push_back(p.first);
                    }
                }
                result.push_back(vec);
                return;
            }
            vector<pair<int, int> > backup;
            for(auto p : candidate_map) {
                backup.push_back(p);
            }

            for(pair<int, int>& p : backup) {
                candidate_map.erase(p.first);
                int size = min(p.second, target / p.first);
                my_stack.push_back(make_pair(p.first, 1));
                for(int i=1; i<=size; ++i) {
                    my_stack[my_stack.size() - 1].second = i;
                    combinationSum2(candidate_map, target - i*p.first, my_stack, result);
                }
                my_stack.pop_back();
            }

            for(auto p : backup) {
                candidate_map.insert(p);
            }
        }
};

int main() {
    int data[] = {10,1,2,7,6,1,5};
    vector<int> vec(data, data+7);
    Solution s;
    vector<vector<int> > result = s.combinationSum2(vec, 8);
    for(auto v: result) {
        for(auto x: v) {
            cout << x << "\t";
        }
        cout << endl;
    }
    return 0;
}

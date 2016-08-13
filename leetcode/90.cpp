#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<int> > subsetsWithDup(vector<int>& nums) {
            map<int, int> dicMap;
            for(int i=0; i<nums.size(); ++i) {
                if(dicMap.find(nums[i]) == dicMap.end()) {
                    dicMap[nums[i]] = 1;
                } else {
                    ++dicMap[nums[i]];
                }
            }

            vector<pair<int, int> > dic;
            for(auto entry : dicMap) {
                dic.push_back(entry);
            }
            vector<pair<int, int> > state;
            vector<vector<int> > result;
            recursive(result, dic, state);
            return result;
        }
        void recursive(vector<vector<int> >& result, vector<pair<int, int> >& dic, vector<pair<int, int> >& state) {
            if(state.size() == dic.size()) {
                // generate one and insert it to result
                vector<int> vec;
                for(int i=0; i<state.size(); ++i) {
                    for(int k=0; k<state[i].second; ++k) {
                        vec.push_back(state[i].first);
                    }
                }
                result.push_back(vec);
            } else {
                // loop over current level
                int pos = state.size();
                int iteration = dic[pos].second;

                for(int i=0; i<=iteration; ++i) {
                    state.push_back(make_pair(dic[pos].first, i));
                    recursive(result, dic, state);
                    state.pop_back();
                }
            }
        }
};

int main() {
    return 0;
}

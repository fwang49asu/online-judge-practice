#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

class Solution {
    public:
        vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
            vector<vector<int> > result;
            set<int> candidate_set;
            for(int x : candidates) {
                candidate_set.insert(x);
            }
            vector<pair<int, int> > my_stack;
            combinationSum(candidate_set, target, my_stack, result);
            return result;
        }
        void combinationSum(set<int>& candidate_set, int target, vector<pair<int, int> >& my_stack, vector<vector<int> >& result) {
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
            vector<int> backup;
            for(int x: candidate_set) {
                backup.push_back(x);
            }
            for(int x : backup) {
                candidate_set.erase(x);
                int size = target / x;
                my_stack.push_back(make_pair(x, 1));
                for(int i=1; i<=size; ++i) {
                    my_stack[my_stack.size() - 1].second = i;
                    combinationSum(candidate_set, target - i*x, my_stack, result);
                }
                my_stack.pop_back();
            }
            for(int x: backup) {
                candidate_set.insert(x);
            }
        }
};

int main() {
    Solution s;
    int data[] = {2, 3, 6, 7};
    vector<int> vec(data, data+4);
    vector<vector<int> > result = s.combinationSum(vec, 7);
    for(auto v: result) {
        for(int x : v) {
            cout << x << "\t";
        }
        cout << endl;
    }
    return 0;
}

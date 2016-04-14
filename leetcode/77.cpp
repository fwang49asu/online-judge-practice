#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        vector<vector<int> > combine(int n, int k) {
            vector<int> curvec;
            vector<vector<int> > result;
            combineRecursive(n, k, curvec, result);
            return result;
        }

    private:
        void combineRecursive(int n, int k, vector<int>& curvec, vector<vector<int> >& result) {
            if(k == 0) {
                vector<int> vec;
                for(int i=1; i<=curvec.size(); ++i) {
                    vec.push_back(curvec[curvec.size() - i]);
                }
                result.push_back(vec);
                return;
            }
            if(n == k) {
                vector<int> vec;
                for(int i=1; i<=n; ++i) {
                    vec.push_back(i);
                }
                for(int i=1; i<=curvec.size(); ++i) {
                    vec.push_back(curvec[curvec.size() - i]);
                }
                result.push_back(vec);
                return;
            }
            for(int i=n; i>=k; --i) {
                curvec.push_back(i);
                combineRecursive(i-1, k-1, curvec, result);
                curvec.pop_back();
            }
        }
};

int main() {
    int n = 5;
    int k = 3;
    Solution s;
    vector<vector<int> > result = s.combine(n, k);
    for(int i=0; i<result.size(); ++i) {
        for(int k=0; k<result[i].size(); ++k) {
            cout << result[i][k] << "\t";
        }
        cout << endl;
    }
    return 0;
}

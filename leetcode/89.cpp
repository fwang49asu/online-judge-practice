#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> grayCode(int n) {
            if(n == 0) {
                vector<int> v;
                v.push_back(0);
                cache.push_back(v);
                return cache[0];
            }

            if(cache.size() >= n) {
                return cache[n];
            }
            if(n == 1) {
                vector<int> v;
                v.push_back(0);
                v.push_back(1);
                cache.push_back(vector<int>());
                cache.push_back(v);
                return cache[1];
            }
            vector<int> v;
            vector<int> pre = grayCode(n-1);
            for(int i=0; i<pre.size(); ++i) {
                v.push_back(pre[i]);
            }
            int mask = 1 << (n-1);
            for(int i=pre.size() - 1; i>=0; --i) {
                v.push_back(mask | pre[i]);
            }
            cache.push_back(v);
            return cache[n];
        }

    private:
       vector<vector<int> > cache;
};

int main() {
    int n = 3;
    Solution s;
    vector<int> vec = s.grayCode(n);
    for(int i=0; i<vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}

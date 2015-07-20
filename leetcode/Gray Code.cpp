class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int size=1<<n;
        for(int i=0;i<size;i++)
            res.push_back((i>>1)^i);
        return res;
    }
};
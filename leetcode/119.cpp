class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> a;
        vector<int> b;
        a.push_back(1);
        if(rowIndex == 0) {
            return a;
        }
        for(int i=0; i<rowIndex; ++i) {
            b.push_back(1);
            for(int k=1; k<a.size(); ++k) {
                b.push_back(a[k-1] + a[k]);
            }
            b.push_back(1);
            b.swap(a);
            vector<int> empty;
            b.swap(empty);
        }
        return a;
    }
};

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows == 0) {
            return result;
        }
        for(int i=0; i<numRows; ++i) {
            vector<int> vec;
            vec.push_back(1);
            result.push_back(vec);
        }
        for(int i=1; i<numRows; ++i) {
            for(int k=1; k<result[i-1].size(); ++k) {
                result[i].push_back(result[i-1][k-1] + result[i-1][k]);
            }
            result[i].push_back(1);
        }
        return result;
    }
};

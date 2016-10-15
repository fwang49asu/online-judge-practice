class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        int half = (int)sqrt(n) + 1;
        if(half*half > n) {
            --half;
        }
        vector<vector<int>> result;
        vector<int> buffer;
        for(int i=2; i<=half; ++i) {
            if(n % i != 0) {
                continue;
            }
            buffer.push_back(i);
            helper(n/i, i, buffer, result);
            buffer.pop_back();
        }
        return result;
    }
private:
    void helper(int n, int low, vector<int> buffer, vector<vector<int>>& result) {
        int upper = (int)sqrt(n);
        if(((upper+1) * (upper+1)) <= n) {
            upper = upper+1;
        }
        buffer.push_back(n);
        {
            vector<int> vec(buffer.begin(), buffer.end());
            result.push_back(buffer);
        }
        buffer.pop_back();
        for(; low <= upper; ++low) {
            if(n % low == 0) {
                buffer.push_back(low);
                helper(n / low, low, buffer, result);
                buffer.pop_back();
            }
        }
        buffer.pop_back();
    }
};

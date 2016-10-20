class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if(A.empty()) {
            return 0;
        }
        int result = 0;
        int f = 0;
        int n = A.size();
        int sum = accumulate(A.begin(), A.end(), 0);
        for(int i=1; i<n; ++i) {
            f += i * A[i];
        }
        result = f;
        for(int i=1; i<n; ++i) {
            f += sum - n * A[n-i];
            result = max(f, result);
        }
        return result;
    }
};

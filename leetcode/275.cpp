class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n == 0) {
            return 0;
        }
        if(citations[0] >= n) {
            return n;
        }
        if(citations[n-1] == 0) {
            return 0;
        }
        int low = 0;
        int high = n-1;
        while(low < high) {
            int center = (low + high) >> 1;
            if(citations[center] == (n-center)) {
                return n - center;
            }
            if(citations[center] > (n - center)) {
                high = center;
            } else {
                low = center + 1;
            }
        }
        return n-low;
    }
};

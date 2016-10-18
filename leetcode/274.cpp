class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int i;
        for(i=0; i<n && citations[i] < (n-i); ++i);
        return n-i;
    }
};

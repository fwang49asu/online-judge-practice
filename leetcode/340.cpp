class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.empty() || k == 0) {
            return 0;
        }
        vector<int> count(128, 0);
        int result = 1;
        count[s[0]] = 1;
        int pool = 1;
        int low = 0;
        int high = 0;
        int n = s.length();
        for(high = 1; high < n; ++high) {
            int index = s[high];
            ++count[index];
            if(count[index] > 1) {
                result = max(result, high - low + 1);
                continue;
            }
            ++pool;
            if(pool <= k) {
                result = max(result, high - low + 1);
                continue;
            }
            // shrink from the low end
            for(; pool > k;++low) {
                index = s[low];
                --count[index];
                if(count[index] == 0) {
                    --pool;
                }
            }
        }
        return result;
    }
};

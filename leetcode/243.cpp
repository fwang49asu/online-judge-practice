class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int n = words.size();
        int result = n;
        int index[] = {-n, -n};
        for(int i=0; i<n; ++i) {
            if(word1 == words[i]) {
                index[0] = i;
                result = min(result, abs(index[0] - index[1]));
            }
            if(word2 == words[i]) {
                index[1] = i;
                result = min(result, abs(index[0] - index[1]));
            }
        }
        return result;
    }
};

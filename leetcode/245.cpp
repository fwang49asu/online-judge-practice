class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int n = words.size();
        int result = n;
        int index[] = {-n, -n};
        if(word1 == word2) {
            for(int i=0; i<n; ++i) {
                if(words[i] == word1) {
                    index[0] = i;
                    result = min(result, abs(index[0] - index[1]));
                    index[1] = index[0];
                }
            }
        } else {
            for(int i=0; i<n; ++i) {
                if(words[i] == word1) {
                    index[0] = i;
                    result = min(result, abs(index[0] - index[1]));
                }
                if(words[i] == word2) {
                    index[1] = i;
                    result = min(result, abs(index[0] - index[1]));
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> count_vec(10, 0);
        int n = secret.length();
        for(int i=0; i<n; ++i) {
            ++count_vec[secret[i] - '0'];
        }
        int bull = 0;
        int cow = 0;
        for(int i=0; i<n; ++i) {
            if(secret[i] == guess[i]) {
                guess[i] = 'x';
                --count_vec[secret[i] - '0'];
                ++bull;
            }
        }
        for(int i=0; i<n; ++i) {
            if(guess[i] == 'x') {
                continue;
            }
            int index = guess[i] - '0';
            if(count_vec[index] > 0) {
                --count_vec[index];
                ++cow;
            }
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};

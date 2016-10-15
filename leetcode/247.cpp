class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        dic.push_back("00");
        dic.push_back("11");
        dic.push_back("88");
        dic.push_back("69");
        dic.push_back("96");

        vector<string> result;
        if(n == 0) {
            result.push_back("");
            return result;
        }
        string base = "";
        for(int i=0; i<n; ++i) {
            base += "a";
        }
        int half = n >> 1;

        if((n & 1) == 0) {
            // even
            helper(base, result, n, half-1);
        } else {
            // odd
            for(int i=0; i<3; ++i) {
                base[half] = dic[i][0];
                helper(base, result, n, half-1);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
private:
    vector<string> dic;
    void helper(string& base, vector<string>& result, int n, int index) {
        if(index == -1) {
            string s = base;
            result.push_back(s);
            return;
        }
        for(int i= index == 0 ? 1 : 0; i<5; ++i) {
            base[index] = dic[i][0];
            base[n - 1 - index] = dic[i][1];
            helper(base, result, n, index-1);
        }
    }
};

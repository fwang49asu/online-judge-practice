class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_set<char> dic;
        unordered_map<char, unordered_set<char>> next_set;
        unordered_map<char, unordered_set<char>> edges;
        int n = words.size();
        for(string word: words) {
            for(char c : word) {
                dic.insert(c);
            }
        }
        for(int i=1; i<n; ++i) {
            int min_length = min(words[i-1].length(), words[i].length());
            bool found = false;
            for(int k=0; k<min_length && !found; ++k) {
                if(words[i-1][k] != words[i][k]) {
                    dic.erase(words[i-1][k]);
                    next_set[words[i-1][k]].insert(words[i][k]);
                    edges[words[i][k]].insert(words[i-1][k]);
                    found = true;
                }
            }
            if(!found && words[i-1].length() > words[i].length()) {
                return "";
            }
        }
        string result = "";

        while(!dic.empty()) {
            char c = *(dic.begin());
            result += c;
            dic.erase(dic.begin());
            unordered_set<char>& range = edges[c];
            for(char p : range) {
                next_set[p].erase(c);
                if(next_set[p].empty()) {
                    next_set.erase(p);
                    dic.insert(p);
                }
            }
        }
        if(!next_set.empty()) {
            return "";
        }
        n = result.length();
        int half = n >> 1;
        for(int i=0; i<half; ++i) {
            swap(result[i], result[n-1-i]);
        }
        return result;
    }
};

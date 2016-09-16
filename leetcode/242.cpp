class Solution {
public:
    bool isAnagram(string s, string t) {
        string a = s;
        string b = t;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }
};

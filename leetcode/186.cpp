class Solution {
public:
    void reverseWords(string &s) {
        int n = s.length();
        reverse(s, 0, n-1);
        int low = 0;
        for(int i=1; i<n; ++i) {
            if(s[i] == ' ') {
                reverse(s, low, i-1);
                low = i+1;
            }
        }
        reverse(s, low, n-1);
    }
    void reverse(string& s, int low, int high) {
        for(; low < high; ++low, --high) {
            swap(s[low], s[high]);
        }
    }
};

class Solution {
public:
  string longestPalindrome(string s) {
    if (s.length() == 0) {
      return "";
    }
    int n = s.length();
    
    int maxLength = 1;
    int maxStart = 0;
    for (int i = 0; i < n;) {
      int low = i;
      int high = i + 1;
      // initial expansion
      while (high < n && s[i] == s[high]) {
        ++high;
      }
      int next = high;
      --low;
      while (low >= 0 && high < n && s[low] == s[high]) {
        --low;
        ++high;
      }
      ++low;
      --high;
      int length = high - low + 1;
      if (length > maxLength) {
        maxLength = length;
        maxStart = low;
      }
      i = next;
    }
    return s.substr(maxStart, maxLength);
  }
};

#include <string>
#include <iostream>

using namespace std;

class Solution {
    public:
        int lengthOfLastWord(string s) {
            int n = s.length();
            int high = n-1;
            for(; high>=0 && s[high] == ' '; --high);
            int low = high;
            for(; low>=0 && s[low] != ' '; --low);
            return high - low;
        }
};

int main() {
    Solution s;
    cout << s.lengthOfLastWord("HelloWorld") << endl;
    return 0;
}

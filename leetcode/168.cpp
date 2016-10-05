#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        stringstream ss;
        while(n > 0) {
            ss << (char)('A' + ((n-1) % 26));
            n = (n-1) / 26;
        }
        string s = ss.str();
        for(int low = 0, high = s.length() - 1; low < high; ++low, --high) {
            swap(s[low], s[high]);
        }
        return s;
    }
};

int main() {
    Solution s;
    cout << s.convertToTitle(29) << endl;
    return 0;
}

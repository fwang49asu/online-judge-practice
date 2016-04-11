#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    public:
        string addBinary(string a, string b) {
            int lengthA = a.length();
            int lengthB = b.length();
            int carry = 0;
            string result = "";
            int maxLength = max(lengthA, lengthB);
            for(int i=0; i<maxLength; ++i) {
                int x = i < lengthA ? (a[lengthA - 1 - i] - '0') : 0;
                int y = i < lengthB ? (b[lengthB - 1 - i] - '0') : 0;
                int sum = x+y+carry;
                result += (char)('0' + (sum & 1));
                carry = ((sum & 2) >> 1);
            }
            if(carry > 0) {
                result += '1';
            }
            revert(result);
            return result;
        }
    private:
        void revert(string& a) {
            int length = a.length();
            int half = length / 2;
            int i, k;
            for(i=0, k=length - 1; i<k; ++i, --k) {
                char t = a[i];
                a[i] = a[k];
                a[k] = t;
            }
        }
};

int main() {
    Solution s;
    cout << s.addBinary("11", "1") << endl;
    return 0;
}

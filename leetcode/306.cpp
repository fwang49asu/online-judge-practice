#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        int half = n >> 1;
        for(int i=1; i<=half; ++i) {
            string left = num.substr(0, i);
            string right = num.substr(i, n - i);
            if(isAdditiveNumber(left, right)) {
                return true;
            }
        }
        return false;
    }

    bool isAdditiveNumber(string left, string right) {
        int rn = right.length();
        int ln = left.length();
        for(int i=1; i<=rn - ln; ++i) {
            string rl = right.substr(0, i);
            string rr = right.substr(i, rn - i);
            if((left.length() > 1 && left[0] == '0') || (rl.length() > 1 && rl[0] == '0')) {
                continue;
            }
            string sum = Add(left, rl);
            if(!StartsWith(rr, sum)) {
                continue;
            }
            if(sum.length() == rr.length()) {
                return true;
            }
            if(isAdditiveNumber(rl, rr)) {
                return true;
            }
        }
        return false;
    }
    bool StartsWith(string& a, string& b) {
        if(a.length() < b.length()) {
            return false;
        }
        int n = b.length();
        for(int i=0; i<n; ++i) {
            if(a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
    string Add(string a, string b) {
        if(a.length() > b.length()) {
            a.swap(b);
        }
        reverse(a);
        reverse(b);
        string result = "";
        int carry = 0;
        int n = a.length();
        for(int i=0; i<n; ++i) {
            int t = a[i] + b[i] - '0' - '0' + carry;
            carry = t / 10;
            t %= 10;
            result += (char)('0' + t);
        }
        int bn = b.length();
        for(int i=n; i<bn; ++i) {
            int t = b[i] + carry - '0';
            carry = t / 10;
            t %= 10;
            result += (char)('0' + t);
        }
        if(carry == 1) {
            result += "1";
        }
        reverse(result);
        return result;
    }

    void reverse(string& a) {
        int n = a.length();
        int half = n >> 1;
        for(int i=0; i<half; ++i) {
            swap(a[i], a[n - 1 - i]);
        }
    }
};

int main() {
    Solution s;
    cout << s.Add("8", "9") << endl;
    cout << s.isAdditiveNumber("101") << endl;
    return 0;
}

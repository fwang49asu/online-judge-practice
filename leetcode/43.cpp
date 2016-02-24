#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        string multiply(string num1, string num2) {
            if(num1.compare("0") == 0|| num2.compare("0") == 0) {
                return "0";
            }
            if(num1.size() < num2.size()) {
                num1.swap(num2);
            }
            string result = "0";
            for(int i=0; i<num2.length(); ++i) {
                string temp = multiplyDigit(num1, num2[num2.length() - i - 1] - '0');
                if(temp.compare("0") == 0) {
                    continue;
                }
                for(int k=0; k<i; ++k) {
                    temp += '0';
                }
                result = add(result, temp);
            }
            return result;
        }
    private:
        string multiplyDigit(string num, int x) {
            if(x == 0) {
                return "0";
            }
            if(x == 1) {
                return num;
            }
            string result = "";
            int carry = 0;
            for(int i=0; i<num.length(); ++i) {
                int t = (num[num.length() - 1 - i] - '0') * x + carry;
                carry = t / 10;
                result = (char)('0' + (t%10)) + result;
            }
            if(carry > 0) {
                result = (char)('0' + carry) + result;
            }
            return result;
        }
        string add(string a, string b) {
            string rev_a = reverse(a);
            string rev_b = reverse(b);
            string result = "";
            int carry = 0;
            int i;
            for(i=0; i<rev_a.length() && i<rev_b.length(); ++i) {
                int t = carry + rev_a[i] - '0' + rev_b[i] - '0';
                carry = t / 10;
                result = (char)((t%10) + '0') + result;
            }
            for(; i<rev_a.length(); ++i) {
                int t = carry + rev_a[i] - '0';
                carry = t / 10;
                result = (char)((t%10) + '0') + result;
            }
            for(; i<rev_b.length(); ++i) {
                int t = carry + rev_b[i] - '0';
                carry = t / 10;
                result = (char)((t%10) + '0') + result;
            }
            if(carry > 0) {
                result = (char)(carry + '0') + result;
            }
            return result;
        }
        string reverse(string a) {
            string result = "";
            for(int i=0; i<a.length(); ++i) {
                result += a[a.length() - i - 1];
            }
            return result;
        }
};

int main() {
    Solution s;
    cout << s.multiply("683283", "87923") << endl;
    return 0;
}

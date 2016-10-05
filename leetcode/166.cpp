#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) {
            return "0";
        }
        if(numerator >= 0 && denominator >= 0) {
            return helper(numerator, denominator);
        }
        if(numerator >= 0 && denominator < 0) {
            return "-" + helper(numerator, -(long long)denominator);
        }
        if(numerator < 0 && denominator >= 0) {
            return "-" + helper(-(long long)numerator, denominator);
        }
        if(numerator < 0 && denominator < 0) {
            return "-" + helper(-(long long)numerator, -(long long)denominator);
        }
        return "";
    }
private:
    string helper(long long numerator, long long denominator) {
        string result = to_string(numerator / denominator);
        numerator %= denominator;
        if(numerator != 0) {
            result += ".";
        }
        unordered_map<long long, int> index_map;
        numerator *= 10;
        while(numerator != 0) {
            if(index_map.find(numerator) != index_map.end()) {
                int left = index_map[numerator];
                result = result.substr(0, left) + "(" + result.substr(left, result.length()) + ")";
                break;
            }
            index_map[numerator] = result.length();
            long long t = numerator / denominator;
            result += (char)('0' + t);
            numerator = numerator % denominator * 10;
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.fractionToDecimal(1, 3) << endl;
    return 0;
}

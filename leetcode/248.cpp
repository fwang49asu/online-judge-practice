#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        dic.push_back("00");
        dic.push_back("11");
        dic.push_back("88");
        dic.push_back("69");
        dic.push_back("96");
        int low_length = low.length();
        int high_length = high.length();
        int result = 0;
        if((high_length - low_length) > 1) {
            for(int i=low_length+1; i<high_length; ++i) {
                result += FullCount(i);
            }
        }
        if(high_length == low_length) {
            string base = "";
            for(int i=0; i<low_length; ++i) {
                base += 'a';
            }
            CountBoundHelper(base, low, high, low_length, low_length >> 1, 0, result);
        } else {
            string bound = "";
            string base = "";
            for(int i=0; i<low_length; ++i) {
                bound += '9';
                base += 'a';
            }
            CountBoundHelper(base, low, bound, low_length, low_length >> 1, 0, result);
            bound = "1";
            base = "a";
            for(int i=1; i<high_length; ++i) {
                bound += '0';
                base += 'a';
            }
            CountBoundHelper(base, bound, high, high_length, high_length >> 1, 0, result);
        }
        return result;
    }
private:
    vector<string> dic;
    void CountBoundHelper(string& base, string& lower, string& upper, int n, int half, int index, int& count) {
        if(index == half) {
            if((n&1) == 0) {
                // output base
                if(base.compare(lower) >= 0 && base.compare(upper) <= 0) {
                    ++count;
                }
            } else {
                for(int i=0; i<3; ++i) {
                    base[half] = dic[i][0];
                    if(base.compare(lower) >= 0 && base.compare(upper) <= 0) {
                        ++count;
                    }
                }
            }
            return;
        }
        for(int i = (n==0 ? 1 : 0); i<5; ++i) {
            base[index] = dic[i][0];
            base[n-1-index] = dic[i][1];
            CountBoundHelper(base, lower, upper, n, half, index+1, count);
        }

    }
    int FullCount(int n) {
        if(n == 1) {
            return 3;
        }
        int half = n >> 1;
        int result = IntExpo(3, n & 1) * IntExpo(5, half - 1) * 4;
        cout << n << " " << result << endl;
        return result;
    }
    int IntExpo(int base, int n) {
        int result = 1;
        for(int i=0; i<n; ++i) {
            result *= base;
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.strobogrammaticInRange("99", "1000") << endl;
    return 0;
}

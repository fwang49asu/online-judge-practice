#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) {
            return false;
        }
        if(x < 10) {
            return true;
        }
        int leftBase = 10;
        while((x / leftBase) >= 10) {
            leftBase *= 10;
        }
        while(x > 0) {
            int left = x / leftBase;
            int right = x % 10;
            if(left != right) {
                return false;
            }
            x = (x % leftBase) / 10;
            leftBase /= 100;
        }
        return true;
    }
};

#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string s = "";
        if(num >= 1000) {
            int n = num / 1000;
            for(int i=0; i<n; ++i) {
                s = s + "M";
            }
        }
        num = num % 1000;
        if(num >= 900) {
            s += "CM";
        } else if(num >= 500) {
            s += "D";
            for(int i=600; i<=num; i+=100) {
                s += "C";
            }
        } else if(num >= 400) {
            s += "CD";
        } else if(num >= 100) {
            for(int i=100; i<=num; i+=100) {
                s += "C";
            }
        }
        num = num % 100;
        if(num >= 90) {
            s += "XC";
        } else if(num >= 50) {
            s += "L";
            for(int i=60; i<=num; i+=10) {
                s += "X";
            }
        } else if(num >= 40) {
            s += "XL";
        } else if(num >= 10) {
            for(int i=10; i<=num; i+=10) {
                s += "X";
            }
        }
        num = num % 10;
        switch(num) {
            case 0:
                break;
            case 1:
                s += "I";
                break;
            case 2:
                s += "II";
                break;
            case 3:
                s += "III";
                break;
            case 4:
                s += "IV";
                break;
            case 5:
                s += "V";
                break;
            case 6:
                s += "VI";
                break;
            case 7:
                s += "VII";
                break;
            case 8:
                s += "VIII";
                break;
            case 9:
                s += "IX";
                break;
        }
        return s;
    }
};

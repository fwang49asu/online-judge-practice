class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = num.length();
        int half = n / 2;
        for(int i=0; i<half; ++i) {
            if(!IsRotate(num[i], num[n-i-1])) {
                return false;
            }
        }
        if((n & 1) == 1) {
            return num[half] == '0' || num[half] == '1' || num[half] == '8';
        }
        return true;
    }
private:
    bool IsRotate(char a, char b) {
        switch(a) {
        case '0':
            return b == '0';
        case '1':
            return b == '1';
        case '6':
            return b == '9';
        case '8':
            return b == '8';
        case '9':
            return b == '6';
        }
        return false;
    }
};

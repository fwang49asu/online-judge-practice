class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) {
            return 1;
        }
        if(n == 3) {
            return 2;
        }
        if(n == 4) {
            return 4;
        }
        int three = n / 3;
        int result = 1;
        switch(n % 3) {
        case 0:
            result = 1;
            break;
        case 1:
            result = 4;
            --three;
            break;
        case 2:
            result = 2;
            break;
        }
        for(int i=0; i<three; ++i) {
            result *= 3;
        }
        return result;
    }
};

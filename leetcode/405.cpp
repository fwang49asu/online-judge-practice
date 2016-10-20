class Solution {
public:
    string toHex(int num) {
        unsigned int x = num;
        string dic = "0123456789abcdef";
        string result = "";
        while(x > 0) {
            result = dic[x & 15] + result;
            x >>= 4;
        }
        if(result == "") {
            result = "0";
        }
        return result;
    }
};

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string dic[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        if(digits.length() == 0) {
            return result;
        }
        comb(digits, 0, dic, result, "");
        return result;
    }
    
    void comb(string digits, int pos, string dic[], vector<string>& result, string curs) {
        if(pos == digits.size()) {
            result.push_back(curs);
            return;
        }
        for(int i=0; i<dic[digits[pos]-'0'].length(); ++i) {
            string s = curs + dic[digits[pos]-'0'][i];
            comb(digits, pos+1, dic, result, s);
        }
    }
    
};

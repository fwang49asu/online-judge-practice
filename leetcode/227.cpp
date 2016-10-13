#include <iostream>
#include <list>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        list<char> op_list;
        list<long long> value_list;
        int high_pri_count = 0;
        for(int i=0; i<s.length(); ++i) {
            if(s[i] == ' ') {
                continue;
            }
            if(s[i] >= '0' && s[i] <= '9') {
                int k=i;
                for(; k<s.length() && s[k] >= '0' && s[k] <= '9'; ++k);
                value_list.push_back(stoi(s.substr(i, k-i)));
                i = k-1;
                continue;
            }
            if(s[i] == '*' || s[i] == '/') {
                ++high_pri_count;
            }
            op_list.push_back(s[i]);
        }
        list<char>::iterator op_it = op_list.begin();
        list<char>::iterator o_it;
        list<long long>::iterator value_it = value_list.begin();
        list<long long>::iterator v_it;
        while(op_it != op_list.end()) {
            if(*op_it == '*' || *op_it == '/') {
                int a = *value_it;
                v_it = value_it;
                ++value_it;
                value_list.erase(v_it);
                int b = *value_it;
                *value_it = *op_it == '*' ? (a*b) : (a/b);
                o_it = op_it;
                ++op_it;
                op_list.erase(o_it);
            } else {
                ++op_it;
                ++value_it;
            }
        }
        value_it = value_list.begin();
        long long result = *value_it;
        for(op_it = op_list.begin(), ++value_it; op_it != op_list.end(); ++op_it, ++value_it) {
            result = *op_it == '+' ? (result + *value_it) : (result - *value_it);
        }
        return (int)result;
    }
};

int main() {
    Solution s;
    cout << s.calculate("3+2*2") << endl;
    return 0;
}

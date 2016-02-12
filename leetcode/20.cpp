#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> check_stack;
        for(int i=0; i<s.length(); ++i) {
            switch(s[i]) {
                case '(':
                case '[':
                case '{':
                    check_stack.push(s[i]);
                    break;
                case ')':
                    if(check_stack.empty() || check_stack.top() != '(') {
                        return false;
                    }
                    check_stack.pop();
                    break;
                case ']':
                    if(check_stack.empty() || check_stack.top() != '[') {
                        return false;
                    }
                    check_stack.pop();
                    break;
                case '}':
                    if(check_stack.empty() || check_stack.top() != '{') {
                        return false;
                    }
                    check_stack.pop();
                    break;
            }
        }
        return check_stack.empty();
    }
};

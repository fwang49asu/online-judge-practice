class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num_stack;
        for(string x: tokens) {
            if(is_operator(x)) {
                int b = num_stack.top();
                num_stack.pop();
                int a = num_stack.top();
                num_stack.pop();
                num_stack.push(operate(a, b, x));
            } else {
                num_stack.push(stoi(x));
            }
        }
        return num_stack.top();
    }
private:
    bool is_operator(string& s) {
        if(s.length() > 1) {
            return false;
        }
        switch(s[0]) {
        case '-':
        case '+':
        case '*':
        case '/':
            return true;
        }
        return false;
    }
    int operate(int a, int b, string& s) {
        switch(s[0]) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        }
        return 0;
    }
};

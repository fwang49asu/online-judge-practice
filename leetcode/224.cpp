#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<Node> vec;
        vec.push_back(Node(true, '('));
        for(int i=0; i<s.length(); ++i) {
            while(!(vec.back().is_operator) && vec[vec.size() - 2].is_operator && vec[vec.size() - 2].value != '(') {
                long long b = vec.back().value;
                vec.pop_back();
                long long op = vec.back().value;
                vec.pop_back();
                long long a = vec.back().value;
                vec.pop_back();

                long long next = op == '+' ? (a+b) : (a-b);
                vec.push_back(Node(false, next));
            }
            if(s[i] == ' ') {
                continue;
            }
            if(s[i] == '(' || s[i] == '-' || s[i] == '+') {
                vec.push_back(Node(true, s[i]));
                continue;
            }
            if(s[i] == ')') {
                Node x = vec.back();
                vec.pop_back();
                vec.pop_back();
                vec.push_back(x);
                continue;
            }
            int k = i;
            for(k=i; k<s.length() && s[k] >= '0' && s[k] <= '9'; ++k);
            vec.push_back(Node(false, stoi(s.substr(i, k-i))));
            i = k-1;
        }
        while(!(vec.back().is_operator) && vec[vec.size() - 2].is_operator && vec[vec.size() - 2].value != '(') {
            long long b = vec.back().value;
            vec.pop_back();
            long long op = vec.back().value;
            vec.pop_back();
            long long a = vec.back().value;
            vec.pop_back();

            long long next = op == '+' ? (a+b) : (a-b);
            vec.push_back(Node(false, next));
        }
        return (int)(vec.back().value);
    }
private:
    struct Node {
        bool is_operator;
        long long value;
        Node(bool o, long long v) : is_operator(o), value(v) {}
        Node() : is_operator(false), value(0) {}
    };
};

int main() {
    Solution s;
    cout << s.calculate("2-(3-4)") << endl;
    return 0;
}

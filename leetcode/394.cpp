class Solution {
public:
    string decodeString(string s) {
        stack<int> count_stack;
        stack<stringstream> stream_stack;
        count_stack.push(1);
        stream_stack.push(stringstream());
        int cur_count = 0;
        for(char c : s) {
            if(c >= '0' && c <= '9') {
                cur_count = cur_count * 10 + c - '0';
            } else if(c == '['){
                count_stack.push(cur_count);
                stream_stack.push(stringstream());
                cur_count = 0;
            } else if(c == ']') {
                string str = stream_stack.top().str();
                int count = count_stack.top();
                stream_stack.pop();
                count_stack.pop();
                for(int i=0; i<count; ++i) {
                    stream_stack.top() << str;
                }
            } else {
                stream_stack.top() << c;
            }
        }
        return stream_stack.top().str();
    }
};

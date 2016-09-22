class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        int len = q.size();
        for(int i=1; i<len; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
};

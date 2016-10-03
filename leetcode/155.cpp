class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        s.push(x);
        min_heap.push(x);
    }

    void pop() {
        // what to pop?
        int end = top();
        stack<int> back_stack;
        while(min_heap.top() != end) {
            back_stack.push(min_heap.top());
            min_heap.pop();
        }
        min_heap.pop();
        while(!back_stack.empty()) {
            min_heap.push(back_stack.top());
            back_stack.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min_heap.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    stack<int> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

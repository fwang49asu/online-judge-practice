class MyQueue {
    public MyQueue() {
        stack = new Stack<>();
    }

    // Push element x to the back of queue.
    public void push(int x) {
        Stack<Integer> s = new Stack<>();
        while(!stack.isEmpty()) {
            s.push(stack.pop());
        }
        stack.push(x);
        while(!s.isEmpty()) {
            stack.push(s.pop());
        }
    }

    // Removes the element from in front of queue.
    public void pop() {
        stack.pop();
    }

    // Get the front element.
    public int peek() {
        return stack.peek();
    }

    // Return whether the queue is empty.
    public boolean empty() {
        return stack.isEmpty();
    }

    private Stack<Integer> stack;
}

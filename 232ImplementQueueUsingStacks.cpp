class Queue {
public:

    void moveStackA2B(stack<int>& a, stack<int>& b) {
        while(!a.empty()) {
            b.push(a.top());
            a.pop();
        }
    }

    // Push element x to the back of queue.
    void push(int x) {
        moveStackA2B(s, assist);
        s.push(x);
        moveStackA2B(assist, s);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        s.pop();
    }

    // Get the front element.
    int peek(void) {
        return s.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }

private:
    stack<int> s, assist;
};
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        queue<int> tmpq;
        int n = q.size();
        for(int i = 0; i < n-1; ++i) {
            tmpq.push(q.front());
            q.pop();
        }
        q = tmpq;
    }

    // Get the top element.
    int top() {
        queue<int> tmpq;
        int n = q.size();
        for(int i = 0; i < n-1; ++i) {
            tmpq.push(q.front());
            q.pop();
        }
        int res = q.front();
        tmpq.push(res);
        q = tmpq;
        return res;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }

private:
    queue<int> q;
};
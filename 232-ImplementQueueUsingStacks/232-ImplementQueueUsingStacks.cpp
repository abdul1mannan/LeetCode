// Last updated: 10/1/2025, 12:49:09 AM
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {}

    void push(int x) { s1.push(x); }

    int pop() {
        int val;
        if (s2.empty()) {
            while (!s1.empty()) {
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
            val = s2.top();
            s2.pop();
        } else {
            val = s2.top();
            s2.pop();
        }
        return val;
    }

    int peek() {
        int val;
        if (s2.empty()) {
            while (!s1.empty()) {
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
            val = s2.top();

        } else {
            val = s2.top();
        }
        return val;
    }

    bool empty() {
        if (s1.empty() && s2.empty())
            return true;
        else
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
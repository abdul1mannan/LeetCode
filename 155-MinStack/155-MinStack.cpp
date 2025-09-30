// Last updated: 10/1/2025, 12:49:39 AM
class MinStack {
public:
 long long mini;
 stack<long long> st;
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        long long v = val;
        if (st.empty()) {
            st.push(v);
            mini = v;
        } else {
            if (v < mini) {
                long long x = 2LL * v - mini;
                st.push(x);
                mini = v;
            } else {
                st.push(v);
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;
        long long x = st.top();
        st.pop();
        if (st.empty()) {
            mini = INT_MAX;
        } else {
            if (x < mini) {
                mini = 2LL * mini - x;
            }
        }
    }
    
    int top() {
      if (st.empty()) return 0;
      long long x = st.top();
      if (x < mini) return (int)mini;
      return (int)x;
    }
    
    int getMin() {
        if (st.empty()) return 0;
        return (int)mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

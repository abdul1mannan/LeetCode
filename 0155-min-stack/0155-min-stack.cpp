class MinStack {
public:
 int mini;
 stack<int>st;
    MinStack() {
        mini=INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini=min(mini,val);
        }
        else {
            if(mini>val){
             int x=2*val-mini;
             st.push(x);
            mini=min(mini,val);
            }
            else st.push(val);
        }
    }
    
    void pop() {
        if(st.empty()) return;
        int x=st.top();
        st.pop();
        if (st.empty()) {
            mini = INT_MAX;         
        } else {
            if(x<mini){
                mini=2*mini-x;
            }  
           
        }
    }
    
    int top() {
      if(st.empty()) return 0;
       return st.top();
    }
    
    int getMin() {
         if(st.empty()) return 0;
        return mini;
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
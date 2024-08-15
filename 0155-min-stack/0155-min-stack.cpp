class MinStack {
public:
    stack<long long>s;
    long long mini;
    MinStack() {
        while(s.empty()==false) s.pop();
        mini=LLONG_MAX;
    }
    
    void push(int val) {
        long long valu=val;
        if(s.empty()){
            mini=val;
                s.push(valu);
        }
        else{
            if(val<mini){
                s.push(2*valu-mini);
                
                mini=valu;
                
            }
            else{
                s.push(valu);
            }
        }
    }
    
    void pop() {
        if(s.empty()) return ;
        long long t=s.top();
        s.pop();
        
        if(t<mini){
            mini=2*mini-t;
        }

    }
    
    int top() {
         if(s.empty()) return -1;
        long long t=s.top();
  
        
        if(t<mini){
           return mini;
        }
        return t;
    }
    
    int getMin() {
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
class MyQueue {
public:
    
    stack<int>s,s1;
    MyQueue() {
        
    }
    
    void push(int x) {
        while (!s.empty()) {
      s1.push(s.top());
      s.pop();
    }
        s.push(x);
        
          while (!s1.empty()) {
      s.push(s1.top());
      s1.pop();
    }
       
        
    }
    
    int pop() {
        
        int x=s.top();
        s.pop();
        return x;
        
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.size()==0?true:false;
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
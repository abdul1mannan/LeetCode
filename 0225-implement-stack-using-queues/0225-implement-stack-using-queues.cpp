class MyStack {
public:
    queue<int>q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        
        
            while(q1.size()>1){
                int f=q1.front();
                q1.pop();
                q2.push(f);
            }
            
           int a=q1.front();
            q1.pop();
            swap(q1,q2);
            return a;
    
    }
    
    int top() {
         while(q1.size()>1){
                int f=q1.front();
                q1.pop();
                q2.push(f);
            }
            
           int a=q1.front();
          q2.push(a);
        q1.pop();
            swap(q1,q2);
            return a;
           
    }
    
    bool empty() {
        if(q1.size()+q2.size()==0) return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
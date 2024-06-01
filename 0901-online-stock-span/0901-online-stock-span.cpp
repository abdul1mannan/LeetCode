class StockSpanner {
public:
    stack<pair<int,int>>s;
    StockSpanner() {
        
    }
     
    
    void add(int price){
        
        int count=1;
        
        while(!s.empty() && s.top().first<=price){
            count+=s.top().second;
            s.pop();
        }
        s.push({price,count});
    }
    int next(int price) {
        add(price);
        return s.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
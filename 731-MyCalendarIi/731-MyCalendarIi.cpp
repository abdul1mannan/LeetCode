// Last updated: 10/1/2025, 12:48:12 AM
class MyCalendarTwo {
public:
  

    map<int,int>cal;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        
                cal[start]++;
                cal[end]--;
          int count=0;
         for(auto&it:cal){
            count+=it.second;
              if(count>=3){
                  --cal[start];
                  ++cal[end];
             return false;
        }
         }
       

        return true;
      
       
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && (st.top()-'0')>(num[i]-'0')){
                st.pop();
                k=k-1;
            }
            st.push(num[i]);
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        
    
       string res = "";
     while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    } 
        reverse(res.begin(), res.end());
    

    int start = 0;
    while (start < res.size() && res[start] == '0') {
        start++;
    }
    
 
    res = res.substr(start);
    if (res.empty()) {
        return "0";
    }
    
    return res;
    }
};
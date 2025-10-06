class Solution {
public:
    int calculate(string s) {
        long long res = 0;  
        int sign = 1;       
        stack<long long> st; 
        const int n = (int)s.size();
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == ' ') continue;

            if (isdigit(c)) {
                long long num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                --i;               
                res += sign * num;  
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
               
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
               
                int prevSign = (int)st.top(); st.pop();
                long long prevRes = st.top(); st.pop();
                res = prevRes + prevSign * res;
            }
        }
        return (int)res;
    }
};

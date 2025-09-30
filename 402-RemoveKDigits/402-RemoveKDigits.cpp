// Last updated: 10/1/2025, 12:48:46 AM
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string res;

   
        for (char c : num) {
            while (!st.empty() && st.top() > c && k > 0) {
                st.pop();
                k--;
            }
            st.push(c);
        }

    
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

  
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());

    
        int idx = 0;
        while (idx < res.size() && res[idx] == '0') {
            idx++;
        }
        res = res.substr(idx);

        return res.empty() ? "0" : res;
    }
};

// Last updated: 10/1/2025, 12:51:16 AM
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            char a = s[i];

            if (a == '(' || a == '{' || a == '[') {
                st.push(a);
            } else if (!st.empty() && ((a == ')' && st.top() == '(') ||
                       (a == '}' && st.top() == '{') ||
                       (a == ']' && st.top() == '['))) {
                st.pop();
            } else
                return false;
        }

    if(st.empty()){
        return true;
    }
    else return false;
    }
   
};
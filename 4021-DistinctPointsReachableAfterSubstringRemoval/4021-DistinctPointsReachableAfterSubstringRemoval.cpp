// Last updated: 10/1/2025, 12:46:45 AM
class Solution {
public:
    int distinctPoints(string s, int k) {
    set<pair<int, int>> st;
        int n=s.size();
       int x = 0, y = 0;
        for (int i = 0; i < k; i++) {
            if (s[i] == 'L') x--;
            else if (s[i] == 'R') x++;
            else if (s[i] == 'U') y++;
            else if (s[i] == 'D') y--;
        }
        st.insert({x, y});
        for (int i = k; i < n; i++) {
    
            if (s[i] == 'L') x--;
            else if (s[i] == 'R') x++;
            else if (s[i] == 'U') y++;
            else if (s[i] == 'D') y--;

            if (s[i-k] == 'L') x++;
            else if (s[i-k] == 'R') x--;
            else if (s[i-k] == 'U') y--;
            else if (s[i-k] == 'D') y++;

            st.insert({x, y});
        }
        return st.size();
    }
};
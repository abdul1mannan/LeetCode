class Solution {
public:
  
      vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;

    for (int i = 0; i < asteroids.size(); ++i) {
        int curr = asteroids[i];
        bool destroyed = false;

        
        while (!st.empty() && st.top() > 0 && curr < 0) {
            if (abs(st.top()) < abs(curr)) {
                st.pop(); 
            } else if (abs(st.top()) == abs(curr)) {
                st.pop(); 
                destroyed = true;
                break;
            } else {
                destroyed = true;
                break;
            }
        }

        if (!destroyed) {
            st.push(curr);
        }
    }

 
    vector<int> ans(st.size());
    for (int i = st.size() - 1; i >= 0; --i) {
        ans[i] = st.top();
        st.pop();
    }

    return ans;
    }
};
class Solution {
public:
    vector<int> nse(vector<int>& arr) {
        stack<int> st;
        vector<int> ans(arr.size());
        
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return ans;
    }
    
    vector<int> pse(vector<int>& arr) {
        stack<int> st;
        vector<int> ans(arr.size());
        
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nexts = nse(arr);
        vector<int> prevs = pse(arr);
        int total = 0;
        int mod = 1e9 + 7;
        
        for (int i = 0; i < arr.size(); i++) {
            int left = i - prevs[i];
            int right = nexts[i] - i;
            total = (total + (long long)(right * left % mod) * arr[i] % mod) % mod;
        }
        return total;
    }
};

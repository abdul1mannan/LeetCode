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
    
    long long int sumSubarrayMins(vector<int>& arr) {
        vector<int> nexts = nse(arr);
        vector<int> prevs = pse(arr);
        long long int total = 0;
        int mod = 1e9 + 7;
        
        for (int i = 0; i < arr.size(); i++) {
            int left = i - prevs[i];
            int right = nexts[i] - i;
            total = (total + (long long)(right * left) * arr[i] );
        }
        return total;
    }


vector<int> nge(vector<int>& arr) {
    stack<int> st;
    vector<int> ans(arr.size());
    
    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? arr.size() : st.top();
        st.push(i);
    }
    return ans;
}

vector<int> pge(vector<int>& arr) {
    stack<int> st;
    vector<int> ans(arr.size());
    
    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}

long long int sumSubarrayMaxs(vector<int>& arr) {
    vector<int> nextg = nge(arr);
    vector<int> prevg = pge(arr);
    long long int total = 0;
    int mod = 1e9 + 7;
    
    for (int i = 0; i < arr.size(); i++) {
        int left = i - prevg[i];
        int right = nextg[i] - i;
        total = (total + (long long)(right * left) * arr[i]);
    }
    return total;
}
    long long subArrayRanges(vector<int>& nums) {
          return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
    }
};
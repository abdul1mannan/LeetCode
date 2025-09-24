class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n,-1);
        for (int i = 0; i < 2*n; i++) {
            if (st.empty()) {
                st.push(i%n);
            }
            while (!st.empty() && nums[st.top()] < nums[i % n]) {
                ans[st.top()] = nums[i % n];
                st.pop();
            }
            st.push(i%n);
        }

        return ans;
    }
};
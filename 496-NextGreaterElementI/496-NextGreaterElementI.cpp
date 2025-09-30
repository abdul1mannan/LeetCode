// Last updated: 10/1/2025, 12:48:34 AM
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> nge(n, -1);
        stack<int> st; 
        
       
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && st.top() <= nums2[i]) st.pop();
            nge[i] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }


        unordered_map<int,int> nxt;
        nxt.reserve(n * 2);
        for (int i = 0; i < n; ++i) nxt[nums2[i]] = nge[i];
        
        
    
   
        vector<int> res;
        res.reserve(nums1.size());
        for (int x : nums1) res.push_back(nxt[x]);
        return res;
    }
};
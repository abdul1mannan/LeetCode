class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

       vector<int> res(nums1.size(), -1); 
        stack<int> st;
        unordered_map<int, int> m;
        
        for(int i=0; i<nums2.size(); i++)
        {
            int element = nums2[i];
            
            while(!st.empty() && element > st.top())
            {
               
				
                m[st.top()] = element;
                st.pop();
            }
            
            st.push(element);
        }
        
        for(int i=0; i<nums1.size(); i++)
        {
            int ele = nums1[i];
            
            if(m.find(ele) != m.end())
            {
                int next = m[ele];
                res[i] = next; 
            }
                
        }
        
        return res;
    }
};
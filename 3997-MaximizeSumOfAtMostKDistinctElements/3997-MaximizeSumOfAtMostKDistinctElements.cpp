// Last updated: 10/1/2025, 12:46:50 AM
class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        // set<int> s(nums.begin(), nums.end()); 
        // vector<int> ans;

        // for (auto it = s.rbegin(); it != s.rend() && ans.size() < k; ++it) {
        //     ans.push_back(*it);         
        // }
        // return ans;
         sort(nums.begin(), nums.end());          
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        reverse(nums.begin(), nums.end());       
        if ((int)nums.size() > k) nums.resize(k); 
        return nums;
    }
}
;
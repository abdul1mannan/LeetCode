class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int> s(nums.begin(), nums.end()); 
        vector<int> ans;

        for (auto it = s.rbegin(); it != s.rend() && ans.size() < k; ++it) {
            ans.push_back(*it);         
        }
        return ans;
    }
}
;
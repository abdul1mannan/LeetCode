// Last updated: 10/1/2025, 12:46:49 AM
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mini=LLONG_MAX;
        long long maxi=LLONG_MIN;
        for(int i=0;i<nums.size();i++){
               mini=min(mini,(long long)nums[i]);
               maxi=max(maxi,(long long)nums[i]);
        }
        long long res=k*(maxi-mini);
        return res;
    }
};
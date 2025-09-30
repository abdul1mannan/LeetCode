// Last updated: 10/1/2025, 12:51:35 AM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n=nums.size();
   
        int l=0;

        unordered_map<int,int>mp;
        while(l<n){
           int val=nums[l];
           int rem=target-val;
           if(mp.find(rem)!=mp.end()){
              return {l,mp[rem]};
           }
           else {
            mp.insert({val,l});
           }
           l++;
        }
        return {};
    }
};
// Last updated: 10/1/2025, 12:50:28 AM
class Solution {
public:
    
    void subsetsum(int ind,vector<int>&d,vector<int>&nums,vector<vector<int>>&ans){
        ans.push_back(d);
        
       for(int i=ind;i<nums.size();i++){
           if(i!=ind && nums[i]==nums[i-1]) continue;
       
        d.push_back(nums[i]);
        subsetsum(i+1,d,nums,ans);
        d.pop_back();
    }
    }
    vector<vector<int>>subsetsWithDup(vector<int>& nums) {
      // set<vector<int>>sum;
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>d;
        subsetsum(0,d,nums,ans);
        return ans;
        
        
    }
};
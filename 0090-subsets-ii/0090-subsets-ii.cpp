class Solution {
public:
    
    void subsetsum(int ind,vector<int>d,vector<int>&nums,set<vector<int>>&sum){
        if(ind==nums.size()){
            sort(d.begin(),d.end());
            sum.insert(d);
            return;
        }
        d.push_back(nums[ind]);
        subsetsum(ind+1,d,nums,sum);
        d.pop_back();
        subsetsum(ind+1,d,nums,sum);
    }
    vector<vector<int>>subsetsWithDup(vector<int>& nums) {
      set<vector<int>>sum;
        vector<vector<int>>ans;
        int n=nums.size();
        vector<int>d;
        subsetsum(0,d,nums,sum);
        for(auto it:sum){
            ans.push_back(it);
        }
        return ans;
        
        
    }
};
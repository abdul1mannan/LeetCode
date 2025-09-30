// Last updated: 10/1/2025, 12:50:57 AM
class Solution {
public:
    
    void getperm(int n,vector<int>&nums,vector<vector<int>>&ans,vector<int>&d,int freq[]){
        
        if(d.size()==n){
            ans.push_back(d);
            return;
        }
        for(int i=0;i<n;i++){
            if(freq[i]==0){
            d.push_back(nums[i]);
            freq[i]=1;
          getperm(n,nums,ans,d,freq);
            freq[i]=0;
           d.pop_back();    
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>d;
        int n=nums.size();
        int freq[n];
        for(int i=0;i<n;i++){
            freq[i]=0;
        }
        getperm(n,nums,ans,d,freq);
        return ans;
        
    }
};
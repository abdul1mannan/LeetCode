class Solution {
public:
    int lengthLis(int n,vector<int>&nums,int ind,int previndex,vector<vector<int>>&dp){
        
        if(ind==n){
            return 0;
        }
        if(dp[ind][previndex+1]!=-1){
            return dp[ind][previndex+1];
        }
        int notake=lengthLis(n,nums,ind+1,previndex,dp);
        int take=0;
        if(previndex==-1||nums[ind]>nums[previndex]){
           take=1+lengthLis(n,nums,ind+1,ind,dp);
        }
        return dp[ind][previndex+1]=max(take,notake);
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return lengthLis(n,nums,0,-1,dp);
        
      
    }
};
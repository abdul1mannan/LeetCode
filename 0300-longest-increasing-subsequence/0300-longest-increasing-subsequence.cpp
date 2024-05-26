class Solution {
public:
//     int lengthLis(int n,vector<int>&nums,int ind,int previndex,vector<vector<int>>&dp){
        
//         if(ind==n){
//             return 0;
//         }
//         if(dp[ind][previndex+1]!=-1){
//             return dp[ind][previndex+1];
//         }
//         int notake=lengthLis(n,nums,ind+1,previndex,dp);
//         int take=0;
//         if(previndex==-1||nums[ind]>nums[previndex]){
//            take=1+lengthLis(n,nums,ind+1,ind,dp);
//         }
//         return dp[ind][previndex+1]=max(take,notake);
//     }
    
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
        return *max_element(dp.begin(), dp.end());
        
      
    }
};
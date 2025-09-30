// Last updated: 10/1/2025, 12:48:53 AM
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
           int n = nums.size();
    if (n == 0) return 0;

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for (int i = n-1; i >=0; i--) {
        for (int j = i-1; j >=-1; j--) {
           if(j==-1 || nums[i]>nums[j]){
               dp[i][j+1]=max(dp[i+1][j+1],1+dp[i+1][i+1]);
           }
            else {
                dp[i][j+1]=dp[i+1][j+1];
            }
        }
    }
        return dp[0][0];

  
    }
};
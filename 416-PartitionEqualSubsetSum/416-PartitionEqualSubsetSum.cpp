// Last updated: 10/1/2025, 12:48:45 AM
class Solution {
public:
    bool canPartition(vector<int>& nums) {
         int sum = 0;
        int n=nums.size();
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) return false;
        
        int target = sum / 2;
        
           vector<vector<bool>> dp(nums.size()+1, vector<bool>(target + 1, 0));
           for (int i = 0; i <= n; i++) {
              dp[i][0] = true;
       }
        
      for (int i = 1; i <= target; i++) {
        dp[0][i] = false;
      }
        for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
           
            if (nums[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
              
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    return dp[n][target];
        
    }
};
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
            int sumTotal = 0;
    for (int num : nums) {
        sumTotal += num;
       }
    int mod=1e9+7;
     if(sumTotal-target<0) return 0;
    if ((sumTotal - target) % 2 != 0) {
        return 0; 
    }
    int s2=(sumTotal-target)/2;
 int n=nums.size();
      vector<vector<int>> dp(n+1,vector<int>(s2+1,0));
       dp[0][0] = 1;
        for (int i = 1; i <= s2; i++) {
            dp[0][i] = 0;
        }

        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= s2; j++) {
                if (nums[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - nums[i - 1]]) % mod;
                }
            }
        }

        return dp[n][s2];
    }
};
// Last updated: 10/1/2025, 12:46:39 AM
class Solution {
public:
    // vector<int> memo;
    // int cost(int curr, vector<int>& costs) {

    //     if (curr <= 0)
    //         return 0;
    //     if (memo[curr] != -1) return memo[curr];
    //     int s1 = cost(curr - 1, costs) + costs[curr - 1] + 1;
    //     int s2 = cost(curr - 2, costs) + costs[curr - 1] + 4;
    //     int s3 = cost(curr - 3, costs) + costs[curr - 1] + 9;

    //     return memo[curr]=min({s1,s2,s3});
    // }
    int climbStairs(int n, vector<int>& costs) {
      if (n <= 0) return 0;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            int land = costs[i - 1];

            int s1 = dp[i - 1] + land + 1;    
            int s2 = (i >= 2 ? dp[i - 2] + land + 4 : INT_MAX);
            int s3 = (i >= 3 ? dp[i - 3] + land + 9 : INT_MAX); 

            dp[i] = min(s1, min(s2, s3));
        }
        return dp[n];
    }
};
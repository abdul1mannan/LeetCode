class Solution {
public:
    // int choice(int r, int c, vector<vector<int>>& triangle,
    //            vector<vector<int>>& memo) {
    //     int n = triangle.size();
    //     if (r == n - 1)
    //         return triangle[r][c];
    //     if (memo[r][c] != -1)
    //         return memo[r][c];
    //     int same = choice(r + 1, c, triangle, memo);
    //     int plus = choice(r + 1, c + 1, triangle, memo);

    //     return memo[r][c] = triangle[r][c] + min(same, plus);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
            dp[n - 1][i] = triangle[n - 1][i];

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        return dp[0][0];
    }
};
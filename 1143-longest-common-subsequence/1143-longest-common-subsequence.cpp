class Solution {
public:
    // int sameSub(string text1, string text2, int index1, int index2,
    //             vector<vector<int>>& dp) {
    //     for (int i = 0; i <= index1; i++) {
    //         dp[i][0] = 0;
    //     }
    //     for (int i = 0; i <= index2; i++) {
    //         dp[0][i] = 0;
    //     }
    //     for (int i = 1; i <= index1; i++) {
    //         for (int j = 1; j <= index2; j++) {
    //             if (text1[i-1] == text2[j-1]) {
    //                 dp[i][j] = 1 + dp[i - 1][j - 1];
    //             } else {
    //                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    //             }
    //         }
    //     }
    //     return dp[index1][index2];
    // }
    
int sameSub(string text1, string text2, int index1, int index2){
     vector<int> prev(index2 + 1, 0), cur(index2 + 1, 0);
      for (int ind1 = 1; ind1 <= index1; ind1++) {
        for (int ind2 = 1; ind2 <= index2; ind2++) {
            if (text1[ind1 - 1] == text2[ind2 - 1])
                cur[ind2] = 1 + prev[ind2 - 1]; 
            else
                cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
        }
        prev = cur; 
    }

    return prev[index2]; 
}
    int longestCommonSubsequence(string text1, string text2) {
        int count = 0;
        int n = text1.size();
        int m = text2.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return sameSub(text1, text2, n, m);
    }
};
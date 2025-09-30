// Last updated: 10/1/2025, 12:50:08 AM
class Solution {
public:
    int choice(int r, int c, vector <vector<int>> &triangle, vector<vector<int>>& memo) {
        int n = triangle.size();
        if (r == n - 1) return triangle[r][c];
        if(memo[r][c]!=INT_MAX) return  memo[r][c];
        int same = choice(r + 1, c, triangle,memo);
        int plus = choice(r + 1, c + 1, triangle,memo);

        return memo[r][c]=triangle[r][c] + min(same, plus);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n==0) return 0;
        vector<vector<int>> memo(n, vector<int>(n, INT_MAX));
        return choice(0, 0, triangle, memo);
    }
};
// Last updated: 10/1/2025, 12:47:19 AM
class Solution {
public:
    

    int cost(int left, int right, const vector<int>& cuts, vector<vector<int>>& memo) {
        if (right - left == 1)
            return 0;
        if (memo[left][right] != -1)
            return memo[left][right];

        int minCost = INT_MAX;
        for (int i = left + 1; i < right; ++i) {
            int currentCost = (cuts[right] - cuts[left]) + cost(left, i, cuts, memo) +                 cost(i, right, cuts, memo);
            minCost = min(minCost, currentCost);
        }
        memo[left][right] = minCost;
        return minCost;
    }
   int minCost(int n, std::vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
       vector<vector<int>> memo(m, vector<int>(m, -1)); // Initialize memoization table with -1

        return cost(0, m - 1, cuts, memo);
    }

};
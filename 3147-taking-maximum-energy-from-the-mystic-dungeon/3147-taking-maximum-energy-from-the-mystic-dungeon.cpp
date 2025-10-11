class Solution {
    int n, K;
    vector<int> memo;

    int dfs(int i, vector<int>& energy) {
        if (i >= n)
            return 0;
        if (memo[i] != INT_MIN)
            return memo[i];

        int best = energy[i];
        if (i + K < n) {
            best += dfs(i + K, energy);
        }

        return memo[i] = best;
    }

public:
    int maximumEnergy(vector<int>& energy, int k) {
        n = energy.size();
        K = k;
        memo.resize(n, INT_MIN);
        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i, energy));
        }
        return ans;
    }
};
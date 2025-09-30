// Last updated: 10/1/2025, 12:47:47 AM
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n), nse(n);
        stack<int> s1, s2;

    
        for (int i = 0; i < n; i++) {
            while (!s1.empty() && arr[s1.top()] > arr[i]) {
                s1.pop();
            }
            pse[i] = s1.empty() ? (i + 1) : (i - s1.top());
            s1.push(i);
        }


        for (int i = n - 1; i >= 0; i--) {
            while (!s2.empty() && arr[s2.top()] >= arr[i]) {
                s2.pop();
            }
            nse[i] = s2.empty() ? (n - i) : (s2.top() - i);
            s2.push(i);
        }

        long long res = 0;
        int MOD = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            long long contrib = (1LL * arr[i] * pse[i] % MOD) * nse[i] % MOD;
            res = (res + contrib) % MOD;
        }

        return (int)res;
    }
};

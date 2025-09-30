// Last updated: 10/1/2025, 12:49:17 AM
class Solution {
public:
    int rob(vector<int>& nums) {
       int n = nums.size();
    if (n == 1) return nums[0];
    
    
    vector<int> dp1(n + 1, 0);
    dp1[0] = 0;
    dp1[1] = nums[0];
    for (int i = 2; i <= n - 1; ++i) {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i - 1]);
    }
    int max1 = dp1[n - 1];

    
    vector<int> dp2(n + 1, 0);
    dp2[1] = 0; 
    dp2[2] = nums[1];
    for (int i = 3; i <= n; ++i) {
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i - 1]);
    }
    int max2 = dp2[n];

    // Return the maximum of the two cases
    return max(max1, max2);
    }
};
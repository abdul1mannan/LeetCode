class Solution {
public:
    bool subsetsum(vector<int>& nums, int target, int index, vector<vector<int>>& memo) {
        int n = nums.size();
        if (target == 0) return true;
        if (index == n || target < 0) return false;
        
        // Check memoization
        if (memo[index][target] != -1) return memo[index][target];
        
        // Exclude the current number
        bool exclude = subsetsum(nums, target, index + 1, memo);
        
        // Include the current number (only if it does not exceed the target)
        bool include = false;
        if (nums[index] <= target) {
            include = subsetsum(nums, target - nums[index], index + 1, memo);
        }
        
        // Store the result in memo
        return memo[index][target] = include || exclude;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) return false;
        
        int target = sum / 2;
        vector<vector<int>> memo(nums.size(), vector<int>(target + 1, -1));
        return subsetsum(nums, target, 0, memo);
    }
};
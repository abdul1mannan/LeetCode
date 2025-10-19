class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), inc = 1, prevInc = 0, maxLen = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                inc++;
            else {
                prevInc = inc;
                inc = 1;
            }
            if (inc == 2 * k || inc >= k && prevInc >= k) {
                return true;
            }
        }
        return false;
    }
};
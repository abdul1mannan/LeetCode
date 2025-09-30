// Last updated: 10/1/2025, 12:47:12 AM
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return true;

        int drops = 0;
        for (int i = 0; i < n; ++i) {
            int next = nums[(i + 1) % n];
            if (nums[i] > next) {
                ++drops;
                if (drops > 1) return false;
            }
        }
        return true;
    }
};

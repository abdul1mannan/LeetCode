// Last updated: 10/1/2025, 12:51:07 AM
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int L = -1, R = -1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        if (l == n || nums[l] != target)
            return {-1, -1};
        L = l;

        l = 0;
        r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        R = r;

        return {L, R};
    }
};

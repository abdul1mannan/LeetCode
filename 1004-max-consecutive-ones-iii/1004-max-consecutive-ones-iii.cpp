class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int maxi = 0;
        int cnt = 0;
        int n = nums.size();
        for (int r = 0; r < n; r++) {

            if (nums[r] == 0) {
                cnt++;
            }
            if (cnt <= k) {
                maxi = max(maxi, r - l + 1);
            } else {

                if (nums[l] == 0) {
                    cnt--;
                }
                l++;
            }
        }
        return maxi;
    }
};
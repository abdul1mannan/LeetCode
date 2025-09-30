// Last updated: 10/1/2025, 12:46:42 AM
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }
        int cnt = 0;
        bool flag = true;
        int idx = n-1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1] && flag) {
                continue;
            } else if ((nums[i] <= nums[i - 1]) && flag) {
                cnt++;
                idx = i - 1;
                flag = false;
                continue;
            } else if (nums[i] < nums[i - 1] && !flag) {
                continue;
            } else if (nums[i] >= nums[i - 1] && !flag) {
                cnt++;
                idx = i - 1;
            }
            if (cnt > 1) {
                return -1;
            }
        }

        long long  sum1 = abs(pre[idx] - (pre[n] - pre[idx]));
        long long sum2 = abs(pre[idx + 1] - (pre[n] - pre[idx + 1]));

        return min(sum1, sum2);
    }
};
// Last updated: 10/1/2025, 12:49:01 AM
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> q;
        int n = nums.size();
        int maxi = INT_MIN;
        vector<int>ans;
        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            maxi = nums[q.front()];
        }
        ans.push_back(maxi);
        for (int i = k; i < n; i++) {
            if (i - q.front() >= k) {
                q.pop_front();
            }
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }

            q.push_back(i);
            maxi = nums[q.front()];
            ans.push_back(maxi);
        }
        return ans;
        
    }
};
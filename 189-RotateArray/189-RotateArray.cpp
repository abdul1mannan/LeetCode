// Last updated: 10/1/2025, 12:49:30 AM
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums.begin()+n-k, nums.end());
        reverse(nums.begin(), nums.begin()+n-k);
        reverse(nums.begin(), nums.end());
    
    }
};
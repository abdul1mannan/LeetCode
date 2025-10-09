class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int n = nums.size();

        int len = 0;
        int xorr = 0;
    
        for (int i = 0; i < n; i++) {
            xorr ^= nums[i];
        }
        if(xorr!=0){
            return n;
        }
        for (int i = 0; i < n; i++) {
            if(nums[i]!=0){
                len=n-1;
                break;
            }
        }
        return len;
    }
};
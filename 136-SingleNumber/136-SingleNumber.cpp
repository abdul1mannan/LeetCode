// Last updated: 10/1/2025, 12:49:56 AM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor1=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            xor1^=nums[i];
        }
        return xor1;
    }
};
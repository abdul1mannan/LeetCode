// Last updated: 10/1/2025, 12:48:38 AM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
          int maxi=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cnt++;
            }
            else {
                cnt=0;
            }
         maxi=max(maxi,cnt);
        }
        return maxi;
    }
};
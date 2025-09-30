// Last updated: 10/1/2025, 12:49:40 AM
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
         int l=0;
         int r=n-1;
         int mini=INT_MAX;
         while(l<=r){
            int mid=l+(r-l)/2;
            mini=min(mini,nums[mid]);
            if(nums[l]<=nums[r]){
                r=mid-1;
            }
            else if(nums[mid]<nums[l]){
                   r=mid-1;
            }
            else {
                  l=mid+1;
            }
         }
         return mini;
    }
};
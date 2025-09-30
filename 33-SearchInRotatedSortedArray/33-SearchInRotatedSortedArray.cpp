// Last updated: 10/1/2025, 12:51:08 AM
class Solution {
public:
    int search(vector<int>& nums, int target) {
         
         int n=nums.size();
         int l=0;
         int r=n-1;
         while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<nums[l]){
                   
                   if(target>nums[mid] && target<=nums[r]){
                    l=mid+1;
                   }
                   else {
                    r=mid-1;
                   }
            }
            else {
                  if(target<nums[mid] && target>=nums[l]){
                    r=mid-1;
                   }
                   else {
                    l=mid+1;
                   }
            }
         }
         return -1;
    }
};
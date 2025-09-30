// Last updated: 10/1/2025, 12:50:34 AM
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int low=0;
        int mid=0; 
        int high=nums.size()-1;
        while(mid<=high){
            
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                    low=low+1;
                    mid=mid+1;
                
            }
            else if(nums[mid]==1){
                mid=mid+1;
            }
            else{
                swap(nums[mid],nums[high]);
                    high=high-1;
                
            }
        }
    }
};
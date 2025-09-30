// Last updated: 10/1/2025, 12:48:02 AM
class Solution {
public:
      
    bool isIdealPermutation(vector<int>& nums) {
    int n=nums.size();
          int maxi = 0;
        for (int i = 0; i < n - 2; ++i) {
            maxi = max(maxi, nums[i]);
            if (maxi > nums[i + 2]) return false;
        }
        return true;
        
    }
//     int merge(vector<int>&nums,int low,int mid,int high){
        
        
//         vector<int>temp;
//         int left=low;
//         int right=mid+1;
        
//         int count=0;
        
//         while(left<=mid&&right<=high){
//             if(nums[left]>nums[right]){
//                 temp.push_back(nums[right]);
//                 count+=mid-left+1;
//                 right++;
               
//             }
//             else{
//                 temp.push_back(nums[left]);
//                 left++;
//             }
//         }
//         while(left<=mid){
//             temp.push_back(nums[left]);
//             left++;
//         }
//         while(right<=high){
//             temp.push_back(nums[right]);
//             right++;
//         }
//          for (int i = low; i <= high; i++) {
//            nums[i] = temp[i - low];
//     }
//         return count;
//     }
//     int mergeSort(vector<int>& nums,int low,int high){
//         int count=0;
//         int mid=(low+high)/2;
//         if(low>=high){
//             return count;
//         }
//         count+=mergeSort(nums,low,mid);
//         count+=mergeSort(nums,mid+1,high);
//         count+=merge(nums,low,mid,high);
//         return count;
        
//     }
    
  
};
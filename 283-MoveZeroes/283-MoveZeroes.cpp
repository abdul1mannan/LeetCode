// Last updated: 10/1/2025, 12:48:57 AM
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        for(int j=0;j<n;j++){
           if(nums[j]!=0){
            nums[i]=nums[j];
            i++;
           }
        }
        for(int k=i;k<n;k++){
            nums[k]=0;
        }
    }
};
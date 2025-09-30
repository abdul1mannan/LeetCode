// Last updated: 10/1/2025, 12:47:43 AM
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
         int n=nums.size();
        sort(nums.begin(),nums.end());
         int r=n-1;
        for(int i=n-2;i>=1;i--){
           int a =nums[i];
           int b=nums[i-1];
           int c=nums[r];

           if(a+b>c){
            return a+b+c;
           }
           else {
            r--;
           }
        }
        return 0;
    }
};
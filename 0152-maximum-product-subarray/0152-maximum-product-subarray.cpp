class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=0;
        int mini=1;
        int prod=1;
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
      for(int i=0;i<n;i++){
         prod*=nums[i];
         maxi=max(maxi,prod);
          if(prod==0){
              prod=1;
          }
     }
        prod=1;
         for(int i=n-1;i>=0;i--){
         prod*=nums[i];
         maxi=max(maxi,prod);
                       if(prod==0){
              prod=1;
          }
     }
        return maxi;
    }
};
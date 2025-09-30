// Last updated: 10/1/2025, 12:49:42 AM
class Solution {
public:
    #define in double
    int maxProduct(vector<int>& nums) {
         in maxi = LLONG_MIN;
        in prod=1;

        for(int i=0;i<nums.size();i++)
        {
          prod*=nums[i];
          maxi=max(prod,maxi);
          if(prod==0)
           prod=1;
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
          prod*=nums[i];

          maxi=max(prod,maxi);
          if(prod==0)
           prod=1;
        }
        return maxi;
    }
    
};
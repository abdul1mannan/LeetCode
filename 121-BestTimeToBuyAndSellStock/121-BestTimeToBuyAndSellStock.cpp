// Last updated: 10/1/2025, 12:50:07 AM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;

        int n=prices.size();
        int maxi=0;
        for(int i=1;i<n;i++){
          int profit=prices[i]-prices[l];
          if(profit<0){
            l=i;
          }
          else {
            maxi=max(maxi,profit);
          }
        }
        return maxi;
    }
};
class Solution {
public:
    long long int mincoin(vector<int> &coins,int amount,vector<vector<int>> &dp,int index)
    {
        int n=coins.size();
        if(amount<0)
            return INT_MAX;
        if(index==n && amount!=0)
        return INT_MAX;
        if(amount==0)
            return 0;
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        
        long long int exclude=mincoin(coins,amount,dp,index+1);
        long long int include=INT_MAX;
        if(coins[index]<=amount){
           include=1+mincoin(coins,amount-coins[index],dp,index);
   
        }
        return dp[index][amount]=min(exclude,include);
        
        
    }
    int coinChange(vector<int>& coins, int amount) { 
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));
     
         int result = mincoin(coins, amount, dp, 0);
        return result == INT_MAX ? -1 : result;
        
    }
};
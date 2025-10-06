class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int mod = 1e9+7;

        vector<int>dp(high+1,0);
        dp[0]=1;

        for(int i=1;i<=high;i++){
            long long way=0;
            if(i-zero>=0){
                way+=dp[i-zero];
            }
            if(i-one>=0){
                way+=dp[i-one];
            }
            dp[i]=way%mod;
        }

        long long ans=0;
        for(int i=low;i<=high;i++){
            ans+=dp[i];
            ans=ans%mod;
        }
        return (int)ans;
    }
};
class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
      int n=nums.size();
        vector<vector<bool>>dp(n+1, vector<bool>(k+1));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                if(i==0) dp[i][j]=false;
                if(j==0) dp[i][j]=true;
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){

            if(nums[i-1]<=j)
               dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
            else{
               dp[i][j] = dp[i-1][j];
            }
            }
        }

        vector<bool>ans;

        for(int i=1;i<=n;i++){

            auto it=upper_bound(nums.begin(),nums.end(),i);
            if(it==nums.end()){
                ans.push_back(dp[n][k]);
            }
            else {

                int index=it-nums.begin();

                int sz=n-index;
                bool flag=false;
                for(int j=0;j<=k;j++){
                   
                   if(dp[index][j]){
                    int remain=k-j;
                    if(remain%i==0){
                        int time=remain/i;
                        if(time<=sz){
                            flag=true;
                            break;

                        }
                    }
    
                   }
                   if(flag) break;
                }
                ans.push_back(flag);
            }
        }
        return ans;
    }
};
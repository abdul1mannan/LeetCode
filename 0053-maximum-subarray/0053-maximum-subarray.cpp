class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=0;
        int mini=0;
        int mini2=INT_MIN;
        int n=nums.size();
        int f=0;
        if(n==1){
            return nums[0];
        }
        for(int i=0;i<n;i++){
            if(nums[i]+sum<sum){

                mini=nums[i]+sum;
                mini2=max(mini2,mini);
                maxi=max(sum,maxi);
                sum=max(0,mini);
            }
            else {
                f=1;
                sum+=nums[i];
            }
        }
        if(f==1)
        return max(maxi,sum);
        else{
            return mini2;
        }
    }
};
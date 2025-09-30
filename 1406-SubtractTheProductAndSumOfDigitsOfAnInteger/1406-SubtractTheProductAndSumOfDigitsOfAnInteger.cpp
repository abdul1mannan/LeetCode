// Last updated: 10/1/2025, 12:47:29 AM
class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod=1;
        int sum=0;
        while(n!=0){
            int rem=n%10;
            prod=prod*rem;
            sum=sum+rem;
            n=n/10;
        }
       int ans=prod-sum;
       return ans;
    }
    
};
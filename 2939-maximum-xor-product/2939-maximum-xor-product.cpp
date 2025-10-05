class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
      
        int MOD = 1e9 + 7;
        if(n==0) return (a%MOD)*(b%MOD)%MOD;
        while(n--){
            if((min(a,b)&(1LL<<n))==0){
                a^=1LL<<n;
                b^=1LL<<n;
            }
        }
         return (a % MOD) * (b % MOD) % MOD;
    }
};
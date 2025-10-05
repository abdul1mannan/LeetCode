class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
      
        int mod = 1e9 + 7;
        if(n==0) return (a%mod)*(b%mod)%mod;
        long long x = 0;
        long long max_val = 0;

        for (long long i = n - 1; i >= 0; i--) {
            long long mask = 1LL << i;

            bool bit_a = (a & mask) > 0;
            bool bit_b = (b & mask) > 0;
            long long ax = a ^ x;
            long long bx = b ^ x;
            if (bit_a == bit_b) {
              if (bit_a == 0) {
                x |= mask;
            }
            } else {
                if((min(ax,bx)&(mask))==0){
                    x|=mask;
                }
            }
            ax=a^x;
            bx=b^x;
            max_val=(ax%mod) * (bx%mod)%mod;
        }
        return max_val;
    }
};
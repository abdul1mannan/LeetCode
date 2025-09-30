// Last updated: 10/1/2025, 12:47:08 AM
class Solution {
public:
#define mod 1000000007
   long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2)%mod;
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

    int countGoodNumbers(long long n) {
        long long int a = 0;
        long long int b = 0;
        if (n % 2 == 0) {
            a = n / 2;
            b = n / 2;
        }
         else {
            a = (n / 2) + 1;
            b = n / 2;
        }
        long long int res = binpow(5, a);
        long long int res1 = binpow(4, b);
        return (res%mod) * (res1%mod)%mod;
    }
};
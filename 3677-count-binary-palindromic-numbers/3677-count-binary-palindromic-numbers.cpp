class Solution {
public:

long long makePal(long long prefix, bool odd){
    long long res=prefix;
    if(odd) prefix>>=1;

    while(prefix>0){
        res=(res<<1) | (prefix &1);
        prefix>>=1;
    }
    return res;
}
    int countBinaryPalindromes(long long n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 2;

        int cnt = 2;
        int numdigit=log2(n)+1;
        for (int i = 2; i < numdigit; i++) {
            int halfdigit =i/ 2;
            if (i % 2 == 1) {
                halfdigit++;
            }
            int powdig=halfdigit-1;
            cnt+= (1LL << powdig);
        }

        int halfdigit=numdigit/2;
        if(numdigit%2==1) halfdigit++;
        long long prefix=n>>(numdigit-halfdigit);
        long long start=1LL << (halfdigit-1);
        long long total=prefix-start;
        cnt+=total;
        long long pal=makePal(prefix,numdigit%2);
        if(pal<=n) cnt++;
    
        return cnt;





    }
};
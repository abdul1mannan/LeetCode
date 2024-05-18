class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        long long int nn = n;
        if (nn < 0) {
            nn = -1 * nn;
        }

        while (nn > 0) {
            if (nn & 1) 
                res = res * x;
                x = x * x;
                nn >>= 1;
            }
        if (n < 0) {
            return (1.0 / res);
        } else
            return res;
    }
};
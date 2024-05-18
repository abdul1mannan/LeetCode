class Solution {
public:
    int uniquePaths(int m, int n) {
        int steps=m+n-2;
        int r=m-1;
        long long int res=1;
        for(int i=1;i<=r;i++){
            res=res*(steps-r+i)/i;
        }
        return res;
    }
};
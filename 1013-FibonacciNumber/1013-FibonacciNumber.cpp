// Last updated: 10/1/2025, 12:47:44 AM
class Solution {
public:
    int fib(int n) {
        
        if(n==1 || n==0){
            return n;
        }
        return fib(n-1)+fib(n-2);
    }
};
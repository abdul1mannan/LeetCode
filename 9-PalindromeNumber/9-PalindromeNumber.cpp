// Last updated: 10/1/2025, 12:51:25 AM
class Solution {
public:
    bool isPalindrome(int x) {
        int rev = 0; 
        if(x<0) return false;
        int k=x;
        while (x != 0) {
            int digit = x % 10;
         
            if ((rev > INT_MAX / 10) || (rev < INT_MIN / 10)) {
                return 0;
            }
            
            rev = rev * 10 + digit;
            x = x / 10; 
        }
        return rev==k;
     
    }
};
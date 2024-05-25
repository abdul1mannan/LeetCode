class Solution {
public:
    int myAtoi(string s) {
    int signedness = 1, base = 0, i = 0;
    while (s[i] == ' ') { i++; }
    if (s[i] == '-'||s[i] == '+') {
        if(s[i]=='-')
        signedness = -1; 
        i++;
    }
       
    while (s[i] >= '0' && s[i] <= '9') {
        if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && s[i] - '0' > 7)) {
            if (signedness == 1) return INT_MAX;
            else return INT_MIN;
        }
        base  = 10 * base + (s[i++] - '0');
    }
    return base * signedness;
       }
    
};
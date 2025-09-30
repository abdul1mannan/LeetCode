// Last updated: 10/1/2025, 12:50:04 AM
class Solution {
public:
    bool isPalindrome(string s) {
      
    string t = "";
    for (char c : s) {
        if (isalnum(c)) {
            t += tolower(c);
        }
    }

    string p = t;
   reverse(p.begin(), p.end());
    return t == p;
    }
};
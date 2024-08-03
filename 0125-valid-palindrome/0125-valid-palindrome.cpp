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
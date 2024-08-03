class Solution {
public:
    bool isPalindrome(string s) {
      
    std::string t = "";
    for (char c : s) {
        if (isalnum(c)) {
            t += tolower(c);
        }
    }

    std::string p = t;
    std::reverse(p.begin(), p.end());
    return t == p;
    }
};
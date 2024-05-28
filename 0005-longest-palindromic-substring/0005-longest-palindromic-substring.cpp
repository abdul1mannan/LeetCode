class Solution {
public:
     string expandFromCenter(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
         
        return s.substr(left + 1, right-left-1);
     }
    
    string longestPalindrome(string s) {
         if (s.length() <= 1) {
            return s;
        }
        string maxi = s.substr(0, 1);
        for (int i = 0; i < s.length() - 1; i++) {
            string odd = expandFromCenter(s, i, i);
            string even = expandFromCenter(s, i, i + 1);

            if (odd.length() > maxi.length()) {
                maxi = odd;
            }
            if (even.length() > maxi.length()) {
                maxi = even;
            }
        }
        return maxi;
    }
};
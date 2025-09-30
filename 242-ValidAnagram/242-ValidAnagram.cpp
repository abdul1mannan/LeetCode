// Last updated: 10/1/2025, 12:49:00 AM
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return t==s;
        
    }
};
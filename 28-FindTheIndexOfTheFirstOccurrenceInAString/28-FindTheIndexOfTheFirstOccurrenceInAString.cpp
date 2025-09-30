// Last updated: 10/1/2025, 12:51:11 AM
class Solution {
public:
    int strStr(string haystack, string needle) {
          if(haystack.find(needle)!=string::npos){
            return haystack.find(needle);
        }
        return -1;
    }
};
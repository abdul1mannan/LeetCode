class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>st;
        int maximum=0;
        int count=0;
        int start=0;
        for(int i=0;i<s.size();i++){
            if(st.find(s[i])!=st.end() && st[s[i]]>=start){
               start=st[s[i]]+1;
               count=i-st[s[i]];
              st[s[i]]=i;
                
            }
            else {
                count++;
                st[s[i]]=i;
            }
            maximum=max(count,maximum);
        }
        return maximum;
    }
};
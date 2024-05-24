class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string t="";
        int n=strs.size();
        int i=0;
        while(strs[0][i]==strs[n-1][i]&&i<strs[0].size()&&i<strs[n-1].size()){
            t+=strs[0][i];
            i++;
        }
        return t;
    }
};
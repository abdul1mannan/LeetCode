class Solution {
public:
    bool isPalindrome(string s){
        string t=s;
        reverse(t.begin(),t.end());
        if(t==s){
            return true;
        }
        else return false;
    }
    void partitionString(int ind,int n,string &s,vector<vector<string>>&ans,vector<string>&d){
        
        if(ind==n){
            ans.push_back(d);
            return ;
        }
        for(int i=ind;i<n;i++){
          string sub=s.substr(ind,i-ind+1);
         if(isPalindrome(sub)){
         d.push_back(sub);
         partitionString(i+1,n,s,ans,d);
         d.pop_back();
        }
        
           }
           }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>>ans;
        vector<string>d;
        partitionString(0,n,s,ans,d);
        return ans;
    }
};
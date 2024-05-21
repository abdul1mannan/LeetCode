class Solution {
public:
    bool isValid(int i,int ind,vector<string>d,int n){
        
        int row=i;
        int col=ind;
        while(row>=0&&col>=0){
            if(d[row][col]=='Q')
                return false;
                row--;
                col--;
            
        }
        row=i;
        col=ind;
                while(col>=0){
            if(d[row][col]=='Q')
                return false;
                col--;
            
        }
         row=i;
        col=ind;
                while(row<n&&col>=0){
            if(d[row][col]=='Q')
                return false;
                row++;
                col--;
            
        }
        return true;
        
    }
    
    void queen(int ind,vector<string>&d,vector<vector<string>>&ans,int n){
        
        if(ind==n){
            ans.push_back(d);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(i,ind,d,n)){
                d[i][ind]='Q';
                queen(ind+1,d,ans,n);
                d[i][ind]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>d(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            d[i]=s;
        }
        queen(0,d,ans,n);
        return ans;
        
        
    }
};
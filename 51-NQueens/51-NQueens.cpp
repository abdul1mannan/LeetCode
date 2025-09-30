// Last updated: 10/1/2025, 12:50:52 AM
class Solution {
public:
    void solve(int col,vector<string>&d,vector<vector<string>>&ans,int n,vector<int>&leftrow,vector<int>&upperdiagonal,vector<int>&lowerdiagonal){
        if(col==n){
            ans.push_back(d);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftrow[row]==0&&upperdiagonal[row+col]==0&&lowerdiagonal[n-1+row-col]==0){
                d[row][col]='Q';
                leftrow[row]=1;
                upperdiagonal[row+col]=1;
                lowerdiagonal[n-1+row-col]=1;
                solve(col+1,d,ans,n,leftrow,upperdiagonal,lowerdiagonal);
                d[row][col]='.';
                leftrow[row]=0;
                upperdiagonal[row+col]=0;
                lowerdiagonal[n-1+row-col]=0;
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
           vector<int>leftrow(n,0),upperdiagonal(2*n-1,0),lowerdiagonal(2*n-1,0);
               
               solve(0,d,ans,n,leftrow,upperdiagonal,lowerdiagonal);
         // queen(0,d,ans,n);
        return ans;
        
        
    }
//     bool isValid(int i,int ind,vector<string>d,int n){
        
//         int row=i;
//         int col=ind;
//         while(row>=0&&col>=0){
//             if(d[row][col]=='Q')
//                 return false;
//                 row--;
//                 col--;
            
//         }
//         row=i;
//         col=ind;
//                 while(col>=0){
//             if(d[row][col]=='Q')
//                 return false;
//                 col--;
            
//         }
//          row=i;
//         col=ind;
//                 while(row<n&&col>=0){
//             if(d[row][col]=='Q')
//                 return false;
//                 row++;
//                 col--;
            
//         }
//         return true;
        
//     }
    
//     void queen(int ind,vector<string>&d,vector<vector<string>>&ans,int n){
        
//         if(ind==n){
//             ans.push_back(d);
//             return;
//         }
//         for(int i=0;i<n;i++){
//             if(isValid(i,ind,d,n)){
//                 d[i][ind]='Q';
//                 queen(ind+1,d,ans,n);
//                 d[i][ind]='.';
//             }
//         }
//     }
 
};
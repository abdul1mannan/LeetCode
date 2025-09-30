// Last updated: 10/1/2025, 12:47:35 AM
class Solution {
public:
      vector<vector<int>>memo;
      
    int count(int i, int j, vector<int>&v){
        if(j<=i+1) return 0;

        if(memo[i][j]!=-1){
             return memo[i][j];
        }
        int result=INT_MAX;
        for(int k=i+1;k<j;k++){
            result = min(result, count(i,k,v)+count(k,j,v)+v[i]*v[k]*v[j]);
        }
        return memo[i][j]=result;

    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        memo.resize(n+1,vector<int>(n+1,-1));
        return count(0,n-1,values);
        

    }
};
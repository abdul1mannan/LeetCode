class Solution {
public:
    long long int mini(vector<vector<int>>& grid,int row,int col, vector<vector<int>>&dp) 
    {   int n=grid.size();
        int m=grid[0].size();
        if(row==n-1 && col==m-1)
        return grid[row][col];
         if(row>=n || col>=m)
             return INT_MAX;
        
        if(dp[row][col]!=-1)
            return dp[row][col];
     long long int right=INT_MAX,down=INT_MAX;
     if(row<n)
     {
          down=mini(grid,row+1,col,dp)+grid[row][col]; 
     }
     if(col<m)
     {
         right=mini(grid,row,col+1,dp)+grid[row][col];
     }
     return dp[row][col]=min(right,down);
     
    }
    
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        return mini(grid,0,0,dp);
    }
};
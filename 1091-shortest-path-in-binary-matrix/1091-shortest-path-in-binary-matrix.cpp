class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
     
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        if(n==1 && grid[0][0]==0){
            return 1;
        }
        int dx[]={1,-1,0,0,1,-1,1,-1};
        int dy[]={0,0,1,-1,1,-1,-1,1};
        queue<pair<int,int>>q;
        q.push({0,0});
        
        vector<vector<int>>dis(n,vector<int>(n,1e9));
        dis[0][0]=1;
        while(!q.empty()){
            
            auto it=q.front();
            int x=it.first;
            int y=it.second;
        
            q.pop();
          
            for(int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0 && dis[nx][ny]>dis[x][y]+1){
                    dis[nx][ny]=dis[x][y]+1;
                      if(nx==n-1 && ny==n-1){
                return dis[nx][ny];
            }
                    q.push({nx,ny});
                }
            }
        }
        return -1;
    
    }
};
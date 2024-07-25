class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
          if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
        if(n==1 && grid[0][0]==0){
            return 1;
        }
        queue<pair<pair<int,int>,int>>q;
        int dx[8]={1,-1,0,0,1,1,-1,-1};
        int dy[8]={0,0,-1,1,-1,1,-1,1};
        vector<vector<int>>dist(grid.size(),vector<int>(grid[0].size(),1e9));
        q.push({{0,0},1});
        dist[0][0]=1;
        while(!q.empty()){
            auto top=q.front();
            int x=top.first.first;
            int y=top.first.second;
            int dis=top.second;
            q.pop();
            for(int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny]==0 &&                                   dist[nx][ny]>dis+1){
                    dist[nx][ny]=dis+1;
                    if(nx==grid.size()-1 && ny==grid[0].size()-1){
                        return dis+1;
                    }
                    q.push({{nx,ny},dist[nx][ny]});
                    
                }
            }
        }
     return -1;
    }
};
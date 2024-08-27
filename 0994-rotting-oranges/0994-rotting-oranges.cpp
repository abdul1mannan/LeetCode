class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int total=0;
        int rotten=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    rotten++;
                    total++;
                }
                if(grid[i][j]==1){
                    total++;
                }
            }
        }
        
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        int min=0;
        while(!q.empty()){
            int s=q.size();
           
            while(s--){
                
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
         
        
            for(int i=0;i<4;i++){
                int nx=dx[i]+x;
                int ny=dy[i]+y;
                
                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1){
                    q.push({nx,ny});
                    grid[nx][ny]=2;
                    rotten++;
                }
            }
            }
           if(!q.empty()){
               min++;
           }
            
        }
        if(rotten==total){
            return min;
        }
        else return -1;
    }
};
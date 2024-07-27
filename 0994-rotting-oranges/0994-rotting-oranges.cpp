class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
     
        
        int rotten=0;
        int total=0;
        queue<pair<int,int>>q;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==2){
                    
                        total++;
                        q.push({i,j});
                    }
                    if(grid[i][j]==1){
                        total++;
                    }
                }
            }
        int cnt=0;
        while(!q.empty()){
            rotten=q.size();
            
             while(rotten--){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
          
          
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 &&ny>=0 &&nx<n && ny<m && grid[nx][ny]==1){
                    q.push({nx,ny});
                    grid[nx][ny]=2;
                }
            }
                
                
                
                
                }
             if(!q.empty()){
                     cnt++;
                 }
        }
        int t=0;
           for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                  if(grid[i][j]==2){
                t++;
                        
                    }}}
        if(t==total)
               return cnt;
        
        else return -1;
        
    }
};
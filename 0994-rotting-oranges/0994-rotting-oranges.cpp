class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
         if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt =0;
        queue<pair<int, int>> rotten;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2) rotten.push({i, j});
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!rotten.empty()){
            int k=rotten.size();
            cnt+=k;
            while(k--){
            int x=rotten.front().first;
            int y=rotten.front().second;
            rotten.pop();
            for(int i=0; i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx<0 ||newy<0||newx>=m||newy>=n|| grid[newx][newy]!=1) continue;
                grid[newx][newy]=2;
                rotten.push({newx,newy});
            }
            }
            if(!rotten.empty()) days++;
        }
        if(tot==cnt) return days;
        else return -1;
    }
};
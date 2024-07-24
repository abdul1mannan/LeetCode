class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
              if(board[0][i]=='O' && !vis[0][i]){
                q.push({0,i});
                vis[0][i]=1;
              }
              if(board[n-1][i]=='O' && !vis[n-1][i]){
                q.push({n-1,i});
                vis[n-1][i]=1;
              }
        }
            for(int i=0;i<n;i++){
              if(board[i][0]=='O' && !vis[i][0]){
                q.push({i,0});
                vis[i][0]=1;
              }
              if(board[i][m-1]=='O' && !vis[i][m-1]){
                q.push({i,m-1});
                vis[i][m-1]=1;
              }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
q.pop();
            for(int i=0;i<4;i++){
                int nx=r+dx[i];
                int ny=c+dy[i];
                if(nx>=0 &&ny>=0 && nx<n &&ny<m && board[nx][ny]=='O' && !vis[nx][ny]){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }

        }

         for(int i = 0;i<n;i++) {
            for(int j= 0 ;j<m;j++) {
                if(!vis[i][j] && board[i][j] == 'O') 
                    board[i][j] = 'X'; 
            }
        }
        

    }
};
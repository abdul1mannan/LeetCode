class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        if(n==1 && m==1) return 0;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        
     priority_queue<pair<int,pair<int,int>>,
                       vector<pair<int,pair<int,int>>>,
                       greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        
        while(!q.empty()){
            auto t=q.top();
            int x=t.second.first;
            int y=t.second.second;
            int dis=t.first;
             if(x==n-1 &&y ==m-1){
                       return dist[x][y];
                   }
            q.pop();
           for(int i=0;i<4;i++){
               int nx=x+dx[i];
               int ny=y+dy[i];
               if(nx>=0 && ny>=0 && nx<n && ny<m && dist[nx][ny]>(max(abs(heights[x][y]-heights[nx][ny]),dis)) ){
                 
                   dist[nx][ny]=max(abs(heights[x][y]-heights[nx][ny]),dis);
                  
                   q.push({dist[nx][ny],{nx,ny}});
                   
               }
           }
        }
        return dist[n-1][m-1];
    }
};
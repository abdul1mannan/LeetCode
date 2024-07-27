class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int initial=image[sr][sc];
        if(initial==color){
            return image;
        }
          int n=image.size();
        int m=image[0].size();
        image[sr][sc]=color;
     
        queue<pair<int,int>>q;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        q.push({sr,sc});
        while(!q.empty()){
    
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
          
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 &&ny>=0 &&nx<n && ny<m && image[nx][ny]==initial){
                    q.push({nx,ny});
                    image[nx][ny]=color;
                  
                }
            }
          
        }
        return image;
    
    }
};
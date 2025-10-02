class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        if(image[sr][sc]==color){
            return image;
        }
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int col=image[sr][sc];
        image[sr][sc]=color;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        while(!q.empty()){
            int s=q.size();
            while(s--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && image[nx][ny]==col){
                     image[nx][ny]=color;
                     q.push({nx,ny});
                    }
                    
                }
            }
        }
        return image;
   
    }
};
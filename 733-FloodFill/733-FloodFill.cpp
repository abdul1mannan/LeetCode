// Last updated: 10/1/2025, 12:48:10 AM
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int initial=image[sr][sc];
        if(initial==color){
            return image;
        }
        image[sr][sc]=color;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
    
            q.pop();
            for(int i=0;i<4;i++){
                int nx=dx[i]+x;
                int ny=dy[i]+y;
                
                if(nx>=0 && ny>=0 && nx<n && ny<m && image[nx][ny]==initial){
                    q.push({nx,ny});
                    image[nx][ny]=color;
                }
            }
        }
        return image;
    }
};
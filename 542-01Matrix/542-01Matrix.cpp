// Last updated: 10/1/2025, 12:48:28 AM
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&                      vis[nx][ny] == 0) {
                    vis[nx][ny] = 1;
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        return dist;
    }
};

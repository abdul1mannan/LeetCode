class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }

        queue<pair<pair<int, int>, int>> q;
        int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
        int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        q.push({{0, 0}, 1});
        dist[0][0] = 1;

        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            int x = top.first.first;
            int y = top.first.second;
            int d = top.second;

            if (x == n - 1 && y == n - 1) {
                return d;
            }

            for (int i = 0; i < 8; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0 && dist[nx][ny] > d + 1) {
                    dist[nx][ny] = d + 1;
                    q.push({{nx, ny}, d + 1});
                }
            }
        }

        return -1;
    }
};
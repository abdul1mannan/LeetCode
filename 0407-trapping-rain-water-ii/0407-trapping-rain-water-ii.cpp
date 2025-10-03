class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        if (m <= 2 || n <= 2)
            return 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            minHeap;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            minHeap.push({heightMap[i][0], i, 0});
            minHeap.push({heightMap[i][n - 1], i, n - 1});
            visited[i][0] = visited[i][n - 1] = true;
        }

        for (int j = 1; j < n - 1; ++j) {
            minHeap.push({heightMap[0][j], 0, j});
            minHeap.push({heightMap[m - 1][j], m - 1, j});
            visited[0][j] = visited[m - 1][j] = true;
        }

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int water = 0;

        while (!minHeap.empty()) {
            vector<int> top = minHeap.top();
            minHeap.pop();
            int height = top[0], x = top[1], y = top[2];

            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                    !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    int nh = heightMap[nx][ny];
                    if (nh < height) {
                        water += height - nh;
                    }
                    minHeap.push({max(height, nh), nx, ny});
                }
            }
        }

        return water;
    }
};
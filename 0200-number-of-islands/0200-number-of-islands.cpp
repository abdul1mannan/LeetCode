class Solution {
public:
    void dfs(int row, int col, vector<pair<int,int>>& vec, vector<vector<int>>& vis, vector<vector<char>>& grid, int baserow, int basecol) {
        vis[row][col] = 1;
        vec.push_back({row - baserow, col - basecol});
        int n = grid.size();
        int m = grid[0].size();
        int newrow[] = {-1, 0, 1, 0};
        int newcol[] = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++) {
            int newx = row + newrow[i];
            int newy = col + newcol[i];
            if (newx >= 0 && newy >= 0 && newx < n && newy < m && !vis[newx][newy] && grid[newx][newy] == '1') {
                dfs(newx, newy, vec, vis, grid, baserow, basecol);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<pair<int,int>>> st;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    vector<pair<int,int>> vec;
                    dfs(i, j, vec, vis, grid, i, j);
                    st.push_back(vec);
                }
            }
        }
        return st.size();
    }
};

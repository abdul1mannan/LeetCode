// Last updated: 10/1/2025, 12:47:53 AM

class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                int dx[4] = {1, -1, 0, 0};
                int dy[4] = {0, 0, -1, 1};
                for (int ind = 0; ind < 4; ind++) {
                    int nx = i + dx[ind];
                    int ny = j + dy[ind];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 1) {
                        int nodenum = i * n + j;
                        int adjnode = nx * n + ny;
                        ds.unionBySize(nodenum, adjnode);
                    }
                }
            }
        }
        
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) continue;
                int dx[4] = {1, -1, 0, 0};
                int dy[4] = {0, 0, -1, 1};
                set<int> components;
                for (int ind = 0; ind < 4; ind++) {
                    int nx = i + dx[ind];
                    int ny = j + dy[ind];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 1) {
                        components.insert(ds.findUPar(nx * n + ny));
                    }
                }
                int total = 0;
                for (auto it : components) {
                    total += ds.size[it];
                }
                maxi = max(maxi, total + 1);
            }
        }
        
        for (int i = 0; i < n * n; i++) {
            maxi = max(maxi, ds.size[ds.findUPar(i)]);
        }
        
        return maxi;
    }
};

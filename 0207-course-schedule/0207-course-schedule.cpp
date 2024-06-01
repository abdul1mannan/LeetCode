class Solution {
public:
    bool dfs(int i, vector<int>& vis, vector<int>& temp_vis, vector<vector<int>>& adj) {
        vis[i] = 1;
        temp_vis[i] = 1;

        for (auto it : adj[i]) {
            if (!vis[it]) {
                if (dfs(it, vis, temp_vis, adj)) {
                    return true;
                }
            } else if (temp_vis[it]) {
                return true;
            }
        }

        temp_vis[i] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int n = prerequisites.size();
        vector<int> vis(numCourses, 0);
        vector<int> temp_vis(numCourses, 0);

        for (const auto& pre : prerequisites) {
            int u = pre[1];
            int v = pre[0];
            adj[u].push_back(v);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (!vis[i]) {
                if (dfs(i, vis, temp_vis, adj)) {
                    return false;
                }
            }
        }
        return true;
    }
};

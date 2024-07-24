class Solution {
public:
    // bool dfs(int i, vector<int>& vis, vector<int>& pathvis,
    //          vector<vector<int>>& adj, vector<int>& res) {
    //      vis[i] = 1;
    //       pathvis[i] = 1;

    //     for (auto edge : adj[i]) {

    //         if (!vis[edge]) {
    //             if (dfs(edge, vis, pathvis, adj, res))
    //                 return true;
    //         } else if (pathvis[edge])
    //             return true;
    //     }
    //     pathvis[i] = 0;
    //     res.push_back(i);
    //     return false;
    // }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
           vector<vector<int>> adj(numCourses);
       for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> res;
        int V=adj.size();
        vector<int>indegree(V,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }

        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);
            for(auto edge:adj[node]){
                indegree[edge]--;
                if(indegree[edge]==0){
                    q.push(edge);
                }
            }
        }
        if(res.size()!=V){
            return {};
        }
        else return res;
    }
};
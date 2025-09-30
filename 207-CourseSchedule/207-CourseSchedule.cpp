// Last updated: 10/1/2025, 12:49:21 AM
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
            return false;
        }
        else return true;
    }
};
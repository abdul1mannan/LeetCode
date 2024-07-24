class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<vector<int>>adjRev(V);
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it:graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        vector<int>res;
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
            for(auto edge:adjRev[node]){
                indegree[edge]--;
                if(indegree[edge]==0){
                    q.push(edge);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};
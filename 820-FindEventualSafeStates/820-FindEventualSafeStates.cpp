// Last updated: 10/1/2025, 12:47:56 AM
class Solution {
public:
    
    bool dfs(int i,vector<int>&vis,vector<int>&pathvis,vector<int>&c,vector<vector<int>>&graph){
        vis[i]=1;
        pathvis[i]=1;
        c[i]=0;
        for(auto edge:graph[i]){
            if(!vis[edge]){
                if(dfs(edge,vis,pathvis,c,graph)){
                    c[i]=0;
                    return true;
                }
            }
            else if(pathvis[edge]){ 
                c[i]=0;
                return true;
            }
        }
        pathvis[i]=0;
        c[i]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();

        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        vector<int>c(V,0);
        
        vector<int>res;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,pathvis,c,graph);
            }
        }
        
      for(int i=0;i<V;i++){
          if(c[i]==1){
              res.push_back(i);
          }
      }
        return res;
    }
};
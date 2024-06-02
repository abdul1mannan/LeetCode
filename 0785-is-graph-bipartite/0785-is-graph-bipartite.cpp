class Solution {
public:
    
    bool dfs(int node,int colour, vector<int>&col,vector<vector<int>> &adjList){
        col[node]=colour;
        
        for(auto it:adjList[node]){
            if(col[it]==-1){
                if(dfs(it,!colour,col,adjList)==false) return false;
                
               
            }
             else if(col[it]==colour) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
       vector<vector<int>> adjList(graph.size());
    for (int i = 0; i < graph.size(); ++i) {
        for (int j = 0; j < graph[i].size(); ++j) {
            int neighbor = graph[i][j];
            adjList[i].push_back(neighbor);
            adjList[neighbor].push_back(i); 
        }
            
        }
        int V=adjList.size();
        vector<int>col(V,-1);
        for(int i=0;i<V;i++){
            if(col[i]==-1){
                if(dfs(i,0,col,adjList)==false) return false;
            }
        }
        return true;
    }
};
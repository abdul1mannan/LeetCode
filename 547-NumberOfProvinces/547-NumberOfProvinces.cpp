// Last updated: 10/1/2025, 12:48:25 AM
class Solution {
public:
    
    void dfs(int i,vector<int>&vis,vector<vector<int>>&adj){
        vis[i]=1;
        for(auto edge:adj[i]){
            if(!vis[edge]){
                dfs(edge,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n+1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[j+1].push_back(i+1);
                    adj[i+1].push_back(j+1);
                }
            }
        }
        vector<int>vis(n+1,0);
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
};
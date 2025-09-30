// Last updated: 10/1/2025, 12:47:57 AM
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>>q;
       vector<int>cost(n,1e9);
      vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        cost[src]=0;
        q.push({0,{src,0}});
        
        while(!q.empty()){
            auto it=q.front();
            int x=it.second.first;
            int c=it.second.second;
            int stops=it.first;
            q.pop();
            if(stops>k) continue;
            for(auto edge:adj[x]){
                int node=edge.first;
                int costs=edge.second;
                if(costs+c<cost[node] ){
                    cost[node]=costs+c;
                    q.push({stops+1,{node,cost[node]}});
                    
                }
                
             
            }
        }
     if(cost[dst]==1e9){
         return -1;
     }
        else return cost[dst];
    }
};
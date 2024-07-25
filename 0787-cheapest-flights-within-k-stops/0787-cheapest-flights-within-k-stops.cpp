class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<pair<int,int>,int>>q;
       vector<int>cost(n,1e9);
      vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        cost[src]=0;
        q.push({{src,0},0});
        
        while(!q.empty()){
            auto it=q.front();
            int x=it.first.first;
            int c=it.first.second;
            int stops=it.second;
            q.pop();
            if(stops>k) continue;
            for(auto edge:adj[x]){
                int node=edge.first;
                int costs=edge.second;
                if(costs+c<cost[node] && stops<=k){
                    cost[node]=costs+c;
                    q.push({{node,cost[node]},stops+1});
                    
                }
                
             
            }
        }
     if(cost[dst]==1e9){
         return -1;
     }
        else return cost[dst];
    }
};
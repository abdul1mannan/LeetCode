// Last updated: 10/1/2025, 12:47:07 AM
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1e9+7;
          vector<vector<pair<int, int>>> adj(n);

 
    for (auto& it : roads) {
        adj[it[0]].push_back({it[1], it[2]});
             adj[it[1]].push_back({it[0], it[2]});
    }
        vector<long long int>dis(n,LLONG_MAX);
        dis[0]=0;
        
        priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>q;
        q.push({0,0});
        vector<int>count(n,0);
        count[0]=1;
        while(!q.empty()){
            int t=q.top().second;
            long long int dist=q.top().first;
            q.pop();
            for(auto &it:adj[t]){
                 int node=it.first;
                long long int time=it.second;
                if((time+dist)<dis[node]){
                    dis[node]=time+dist;
                    count[node]=count[t];
                    q.push({time+dist,node});
                }
                else if(time+dist==dis[node]){
                    count[node]=(count[node]+count[t])%mod;
                }
            }
        }
        return count[n-1]%mod;
    }
};
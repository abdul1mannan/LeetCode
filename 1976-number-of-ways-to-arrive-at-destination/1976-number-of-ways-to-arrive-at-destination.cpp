class Solution {
public:
    
    long long mod = (long long)1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector <vector<pair<long long,long long>>> adj(n);
        for(int i=0 ; i<roads.size() ; i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        // Time , Node 
        priority_queue <pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        vector <long long> time(n,LLONG_MAX);
        vector <long long> ways(n,0);

        pq.push({0,0});
        time[0] = 0;
        ways[0] = 1;

        while(!pq.empty()){

            long long t = pq.top().first;
            long long node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                long long v = it.first;
                long long wt = it.second;
                if(t + wt < time[v]){
                    time[v] = t + wt;
                    ways[v] = ways[node];
                    pq.push({time[v],v});
                }
                else if(t + wt == time[v] ){
                    ways[v] = (ways[v] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};

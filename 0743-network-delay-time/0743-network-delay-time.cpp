class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
           vector<vector<pair<long long, long long>>> adj(n+1);

    
        for (auto& it : times) {
            adj[it[0]].emplace_back(it[1], it[2]);

        }
          vector<long long> dist(n+1,LLONG_MAX);
      
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,          greater<pair<long long, long long>>> q;

      
        dist[k] = 0;
      
        q.push({0, k});

        while (!q.empty()) {
            long long int d = q.top().first;
            long long node = q.top().second;
            q.pop();

            for (auto edge : adj[node]) {
                long long int adjNode = edge.first;
                long long cost = edge.second;

                if (cost + d < dist[adjNode]) {
                    dist[adjNode] = cost + d;
                   q.push({dist[adjNode], adjNode});
                } 
            }
        }
        long long int time=LLONG_MIN;

        for(int i=1;i<=n;i++){
            if(dist[i]==LLONG_MAX){
                return -1;
            }
            time=max(time,dist[i]);
        }
      
    return time;

    }
};
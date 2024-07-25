class Solution {
public:
     long long mod = (long long)1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
    
        vector<vector<pair<long long, long long>>> adj(n);

        // Building adjacency list
        for (auto& it : roads) {
            adj[it[0]].emplace_back(it[1], it[2]);
            adj[it[1]].emplace_back(it[0], it[2]);
        }

        vector<long long> dist(n,LLONG_MAX);
        vector<long long> ways(n, 0);
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,          greater<pair<long long, long long>>> q;

        // Starting from node 0
        dist[0] = 0;
        ways[0] = 1;
        q.push({0, 0});

        while (!q.empty()) {
            long long int d = q.top().first;
            long long node = q.top().second;
            q.pop();

            for (auto edge : adj[node]) {
                long long int adjNode = edge.first;
                long long cost = edge.second;

                if (cost + d < dist[adjNode]) {
                    dist[adjNode] = cost + d;
                   
                    ways[adjNode] = ways[node];
                     q.push({dist[adjNode], adjNode});
                } else if (cost + d == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return (ways[n - 1] % mod);
    }
};

// Last updated: 10/1/2025, 12:48:07 AM
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      vector<vector<pair<int, int>>> adj(n + 1);

 
    for (auto& it : times) {
        adj[it[0]].push_back({it[1], it[2]});
    }

    vector<int> dis(n + 1, 1e9);
    dis[k] = 0; 


    queue<int> q;
    q.push(k);


    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto& it : adj[node]) {
            int nextNode = it.first;
            int time = it.second;
            if (dis[node] + time < dis[nextNode]) {
                dis[nextNode] = dis[node] + time;
                q.push(nextNode); 
            }
        }
    }


    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dis[i] == 1e9) {
            return -1; 
        }
        maxTime = max(maxTime, dis[i]);
    }

    return maxTime;
}
};
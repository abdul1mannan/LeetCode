class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int>dis(n+1,1e9);
        dis[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k});
        
        while(!q.empty()){
            int t=q.top().second;
            int dist=q.top().first;
            q.pop();
            for(auto &it:adj[t]){
                int node=it.first;
                int time=it.second;
                if((time+dist)<dis[node]){
                    dis[node]=time+dist;
                    q.push({time+dist,node});
                }
            }
        }
        int mini=0;
        for(int i=1;i<=n;i++){
            if(dis[i]==1e9){
                return -1;
            }
            mini=max(mini,dis[i]);
        }
        return mini;
    }
};
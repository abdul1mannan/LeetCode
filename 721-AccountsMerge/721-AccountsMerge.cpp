// Last updated: 10/1/2025, 12:48:16 AM
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        sort(accounts.begin(),accounts.end());
        unordered_map<string,int>mp;
        
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
              string mail=accounts[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail]=i;
                }
                else{
                    ds.unionBySize(i,mp[mail]);
                }
            }
        }
        
        vector<vector<string>>merg(n);
        for(auto it:mp){
            string email=it.first;
            int node=ds.findUPar(it.second);
            merg[node].push_back(email);
        }
        vector<vector<string>>ans;
        
        for(int i=0;i<n;i++){
            if(merg[i].size()==0) continue;
            sort(merg[i].begin(),merg[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:merg[i]){
                temp.push_back(it);
                
                
            }
            ans.push_back(temp);
            
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
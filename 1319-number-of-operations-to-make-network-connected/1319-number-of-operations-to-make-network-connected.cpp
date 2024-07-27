class dsu{
    vector<int>parent,size;
    public:
    dsu(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    
    int findpar(int node){
        if(node==parent[node]){
        return node;    
        }
        return parent[node]=findpar(parent[node]);
        
    }
    
    void unionbysize(int u,int v){
        int up=findpar(u);
        int vp=findpar(v);
        if(up==vp) return;
        
        if(size[up]<size[vp]){
            size[vp]+=size[up];
            parent[up]=vp;
        }
        else{
             size[up]+=size[vp];
            parent[vp]=up;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        dsu ds(n);
         int extra=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findpar(u)==ds.findpar(v)){
                extra++;
            }
            else {
                ds.unionbysize(u,v);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.findpar(i)==i) cnt++;
        }
        if(extra>=(cnt-1)) return (cnt-1);
        else return -1;
    }
};
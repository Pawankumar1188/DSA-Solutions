class DSU{
    vector<int>parent,size;
    public:
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
            
        }
    }
    int ultimateP(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=ultimateP(parent[u]);
    }
    bool unionbysize(int u,int v){
        int ultpu=ultimateP(u);
        int ultpv=ultimateP(v);
        if(ultpu == ultpv) return false;
        if(size[ultpu]<size[ultpv]){
            parent[ultpu]=ultpv;
            size[ultpv]+=size[ultpu];
        }
        else{
            parent[ultpv]=ultpu;
            size[ultpu]+=size[ultpv];
        }
        return true;
    }
    
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }

        int component=n;
        DSU ds(n);
        for (auto &edge : connections) {
            if (ds.unionbysize(edge[0], edge[1])) {
                component--;
            }
        }

        return component-1;
    }
};
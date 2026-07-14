class DSU{
    vector<int>parent,size;
    public:
    DSU(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int ultimateP(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=ultimateP(parent[u]);
    }
    void unionbysize(int u,int v){
        int ultpu=ultimateP(u);
        int ultpv=ultimateP(v);
        if(ultpu == ultpv) return;
        if(size[ultpu]<size[ultpv]){
            parent[ultpu]=ultpv;
            size[ultpv]+=size[ultpu];
        }
        else{
            parent[ultpv]=ultpu;
            size[ultpu]+=size[ultpv];
        }
    }
    int sz(){
        set<int>s;
        for(int i=0;i<parent.size();i++){
            s.insert(ultimateP(i));
        }
        return s.size();
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }

        DSU ds(n);
        for(int i=0;i<connections.size();i++){
            ds.unionbysize(connections[i][0],connections[i][1]);
            cout<<i<<endl;
        }
        return ds.sz()-1;
    }
};
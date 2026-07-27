class dsu{
    
    public:
    vector<int>parent,size;
    dsu(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findparent(int i){
        if(parent[i]==i){
            return i;
        }
        return parent[i]=findparent(parent[i]);
    }
    void unite(int u,int v){
        int pu=findparent(u);
        int pv=findparent(v);
        if(pu==pv){
            return;
        }
        if(size[pu]>size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else{
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        dsu ds(n*n);
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    continue;
                }
                for(auto [x,y]:dir){
                    if(i+x>=0&&i+x<n&&j+y>=0&&j+y<n&&grid[x+i][y+j]==1){
                        ds.unite(n*i+j,n*(i+x)+j+y);
                    }
                }

            }
        }
        bool foundzero=false;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    foundzero=true;
                    set<int>ultimatepar;
                    for(auto [x,y]:dir){
                        if(i+x>=0&&i+x<n&&j+y>=0&&j+y<n&&grid[x+i][y+j]==1){
                            ultimatepar.insert(ds.findparent(n*(i+x)+y+j));
                        }
                    }
                    int total=0;
                    for(int s:ultimatepar){
                        total+=ds.size[s];
                    }
                    ans=max(ans,total+1);
                }
                

            }
        }
        if(ans==0&&!foundzero){
            return n*n;
        }
        return ans;
    }
};
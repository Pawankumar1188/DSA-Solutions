class Disjoint {

    vector<int> parent, size;
    public:
    Disjoint(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findparent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findparent(parent[node]);
    }

    void unite(int u, int v) {
        int pu = findparent(u);
        int pv = findparent(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>mp;
        int n=accounts.size();
        Disjoint dsu(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j])==mp.end()){
                    mp[accounts[i][j]]=i;
                }
                else{
                    dsu.unite(i,mp[accounts[i][j]]);
                }
            }
        }
        
        vector<vector<string>>ans;
        vector<vector<string>>dummy(n);
        for(auto [mail,value]:mp){
            int realparent=dsu.findparent(value);
            dummy[realparent].push_back(mail);
        }
        for(int i=0;i<n;i++){
            if(dummy[i].size()==0) continue;
            int realind=dsu.findparent(i);
            vector<string>temp;
            temp.push_back(accounts[realind][0]);
            
            sort(dummy[realind].begin(),dummy[realind].end());
            for(auto e:dummy[realind]){
                temp.push_back(e);
            }
            ans.push_back(temp);

            

        }
        return ans;
    }
};
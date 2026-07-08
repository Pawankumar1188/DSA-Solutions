class Solution {
public:
    void dfs(int n,vector<vector<int>>& graph,vector<int>&color){
        queue<pair<int,int>>q;
        q.push({n,2});
        color[n]=2;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(auto neigh:graph[node.first]){
                if(color[neigh]!=-1){
                    continue;
                }
                if(node.second==2){
                    color[neigh]=1;
                    q.push({neigh,1});
                }
                else{
                    color[neigh]=2;
                    q.push({neigh,2});
                }
                
            }
        }

    }
    bool ans=true;
    void dfs2(int n,vector<vector<int>>& graph,vector<int>&color){
        queue<int>q;
        q.push(n);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto neigh:graph[node]){
                if(color[neigh]!=3 && color[node]==color[neigh]){
                    ans=false;
                    return;
                }
                else if(color[neigh]!=3){
                    q.push(neigh);
                }
            }
            color[node]=3;

        }

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                dfs(i,graph,color);
            }
        }
        for(int i=0;i<n;i++){
            cout<<color[i]<<" ";
        }
        //checking agine same color consecutive
        for(int i=0;i<n;i++){
            if(color[i]==2){
                dfs2(i,graph,color);
            }
        }
        return ans;
    }
};
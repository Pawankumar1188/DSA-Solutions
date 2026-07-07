class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>&vis,int p,vector<int>&parent,vector<int>&dfsvis){
        vis[node]=1;
        dfsvis[node]=1;
        parent[node]=p;
        for(int neigh:adj[node]){
            if(!vis[neigh]){
                if(dfs(neigh,adj,vis,node,parent,dfsvis)){
                    return true;
                }
                
            }
            else if(dfsvis[neigh]==1){
                return true;
            }
        }
        dfsvis[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>dfsvis(numCourses,0);
        vector<int>parent(numCourses,-1);
        vector<int>vis(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,-1,parent,dfsvis)){
                    return false;
                }
            }
        }
        return true;
    }
};


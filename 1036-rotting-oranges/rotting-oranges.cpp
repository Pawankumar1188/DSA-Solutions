class Solution {
public:
    int ans=0;
    
    void bfs(vector<vector<int>>& grid,vector<int>&vis,vector<pair<int,int>>&dir,queue<pair<int,int>>&q){
        int m=grid[0].size();
        
        
        
        while(!q.empty()){
            
            int s=q.size();
            bool changed=false;
            for(int i=0;i<s;i++){
                auto node=q.front();
                q.pop();
                for(auto d:dir){
                    int newx=d.first+node.first;
                    int newy=d.second+node.second;
                    if(newx>=0&&newx<grid.size()&&newy>=0&&newy<grid[0].size()&&vis[m*newx+newy]==0&&grid[newx][newy]==1){
                        grid[newx][newy]=2;
                        q.push({newx,newy});
                        changed=true;
                        vis[m*newx+newy] = 1;

                    }
                }
            }
            if(changed){
                ans++;
            }


        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>vis(n*m,0);
        queue<pair<int,int>>q;
        vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[m*i + j] = 1;
                    q.push({i,j});
                    
                }
            }
        }
        
        bfs(grid,vis,dir,q);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                    
                }
            }
        }
        return ans;
    }
};
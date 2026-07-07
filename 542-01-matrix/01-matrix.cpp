class Solution {
public:
    void bfs(queue<pair<int,int>>&q,vector<vector<int>>& grid,vector<vector<int>>& ans,vector<vector<int>>& vis){
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(auto d:dir){
                int newx=d.first+i;
                int newy=d.second+j;
                if(newx>=0&&newx<grid.size()&&newy>=0&&newy<grid[0].size()&&vis[newx][newy]==0){
                    
                    vis[newx][newy]=1;
                    q.push({newx,newy});
                    ans[newx][newy]=ans[i][j]+1;
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n));
        vector<vector<int>>vis(m,vector<int>(n));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                    
                }
            }
        }
        bfs(q,mat,ans,vis);
        return ans;
    }
};

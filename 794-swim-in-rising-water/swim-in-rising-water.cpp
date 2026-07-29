class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(int i,int j,int mid,vector<vector<int>>& grid,vector<vector<int>>& vis){
        int n=grid.size();
        if(i==n-1 && j==n-1){
            return true;
        }
        vis[i][j]=1;
        for(auto [p,q]:dir){
            int newi=i+p;
            int newj=j+q;
            if(newi>=0&&newi<n&&newj>=0&&newj<n&&!vis[newi][newj]&&grid[newi][newj]<=mid){
                if(dfs(newi,newj,mid,grid,vis)){
                    return true;
                }
            }

        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int low=max(grid[0][0],grid[n-1][n-1]);
        int high=n*n-1;
        int ans=low;
        while(low<=high){
            int mid=(high+low)/2;
            vector<vector<int>>vis(n,vector<int>(n,0));
            if(dfs(0,0,mid,grid,vis)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
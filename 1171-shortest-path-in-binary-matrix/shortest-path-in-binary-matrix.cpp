class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        queue<pair<int,int>>q;
        if(grid[0][0]==0){
            q.push({0,0});
            dist[0][0]=0;
        }
        
        
        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();
            for(auto [i_,j_]:dir){
                int ni=i+i_;
                int nj=j+j_;
                if(ni<0||ni>=n||nj<0||nj>=n||grid[ni][nj]==1){
                    continue;
                }
                if(dist[ni][nj]>1+dist[i][j]){
                    dist[ni][nj]=1+dist[i][j];
                    q.push({ni,nj});
                    cout<<ni<<" "<<nj<<endl;
                }
            }
        }
        if(dist[n-1][n-1]==INT_MAX) return -1;
        return dist[n-1][n-1]+1;
    }
};
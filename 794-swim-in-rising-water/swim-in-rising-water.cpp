class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        // vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        pq.push({grid[0][0],{0,0}});
        // dist[0][0]=grid[0][0];
        int ans=0;
        while(!pq.empty()){
            int w=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            
            ans=max(ans,w);
            // cout<<ans<<endl;
            pq.pop();
            for(auto [p,q]:dir){
                int nx=x+p;
                int ny=y+q;
                if(nx>=0&&nx<n&&ny>=0&&ny<n&&grid[nx][ny]!=INT_MAX){
                    pq.push({grid[nx][ny],{nx,ny}});
                    if(nx==n-1&&ny==n-1){
                        return max(ans,grid[nx][ny]);
                    }
                    grid[nx][ny]=INT_MAX;
                    
                }
            }
        }
        return ans;
    }
};
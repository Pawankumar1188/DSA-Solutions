class Solution {
public:
    void bfs(queue<pair<int,int>>&q,vector<vector<int>>&grid,int color){
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        int m=grid.size();
        int n=grid[0].size();
        int srccolor=grid[q.front().first][q.front().second];
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(srccolor==grid[node.first][node.second]){
                grid[node.first][node.second]=color;
            }
            for(auto d:dir){
                int newx=d.first+node.first;
                int newy=d.second+node.second;
                if(newx>=0&&newx<grid.size()&&newy>=0&&newy<grid[0].size()&&grid[newx][newy]==srccolor){
                    q.push({newx,newy});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image;
        }
        queue<pair<int,int>>q;
        q.push({sr,sc});
        bfs(q,image,color);
        return image;
    }
};



class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& board){
        board[i][j]=2;
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(auto [x,y]:dir){
            if(x+i>=0&&x+i<board.size()&&y+j>=0&&y+j<board[0].size()&&board[x+i][y+j]==1){
                dfs(x+i,y+j,board);
            }   
        } 
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        int cnt=0;
        for(int i=0;i<n;i++){
            if(grid[0][i]==1){
                dfs(0,i,grid);
            }
            if(grid[m-1][i]==1){
                dfs(m-1,i,grid);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                dfs(i,0,grid);
            }
            if(grid[i][n-1]==1){
                dfs(i,n-1,grid);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    cnt++;
                }
                
            }
        }
        return cnt;
    }
};
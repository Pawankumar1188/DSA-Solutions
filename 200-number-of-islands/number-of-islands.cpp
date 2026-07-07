class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board){
        board[i][j]='2';
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(auto [x,y]:dir){
            if(x+i>=0&&x+i<board.size()&&y+j>=0&&y+j<board[0].size()&&board[x+i][y+j]=='1'){
                
                dfs(x+i,y+j,board);
            }   
        } 
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    
                    dfs(i,j,grid);
                    cnt++;
                }

            }
            
            
        }
        
        return cnt;
    }
};
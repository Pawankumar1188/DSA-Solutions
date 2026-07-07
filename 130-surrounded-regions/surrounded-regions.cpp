class Solution {
public:
    bool merged=true;
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>&vis){
        
        vis[i][j]=1;
        board[i][j]='z';
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(auto [x,y]:dir){
            if(x+i>=0&&x+i<board.size()&&y+j>=0&&y+j<board[0].size()&&board[x+i][y+j]=='O'){
                dfs(x+i,y+j,board,vis);
            }
            
            
            
        }
        
        
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n));
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'&&!vis[0][i]){
                dfs(0,i,board,vis);
            }
            if(board[m-1][i]=='O'&&!vis[m-1][i]){
                dfs(m-1,i,board,vis);
            }
            
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'&&!vis[i][0]){
                dfs(i,0,board,vis);
            }
            if(board[i][n-1]=='O'&&!vis[i][n-1]){
                dfs(i,n-1,board,vis);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='z'){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }
    }
};
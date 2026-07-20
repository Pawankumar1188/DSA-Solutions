class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int>v;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                v.push_back(grid[i][j]);
            }
        }
        vector<int>ans(n*m);
        for(int i=0;i<m*n;i++){
            ans[(i+k)%(m*n)]=v[i];
        }
        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=ans[c++];
            }
        }
        return grid;
        
    }
};
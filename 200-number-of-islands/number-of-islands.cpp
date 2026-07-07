class Solution {
public:
    vector<pair<int,int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(int i, int j, vector<vector<char>>& grid) {
        grid[i][j] = '2';

        for (auto [dx, dy] : dir) {
            int ni = i + dx;
            int nj = j + dy;

            if (ni >= 0 && ni < grid.size() &&
                nj >= 0 && nj < grid[0].size() &&
                grid[ni][nj] == '1') {
                dfs(ni, nj, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(i, j, grid);
                }
            }
        }

        return islands;
    }
};
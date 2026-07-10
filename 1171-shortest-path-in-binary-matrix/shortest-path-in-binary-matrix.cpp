class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        vector<pair<int,int>> dir = {
            {1,0}, {-1,0}, {0,1}, {0,-1},
            {1,1}, {1,-1}, {-1,1}, {-1,-1}
        };

        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        grid[0][0] = 1;

        while (!q.empty()) {
            auto [cell, len] = q.front();
            q.pop();

            auto [i, j] = cell;

            if (i == n-1 && j == n-1)
                return len;

            for (auto [dx, dy] : dir) {
                int ni = i + dx;
                int nj = j + dy;

                if (ni < 0 || ni >= n || nj < 0 || nj >= n)
                    continue;

                if (grid[ni][nj] == 1)
                    continue;

                grid[ni][nj] = 1; 
                q.push({{ni, nj}, len + 1});
            }
        }

        return -1;
    }
};
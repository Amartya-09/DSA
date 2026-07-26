class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        queue<pair<int,int>> q;
        int fresh = 0;

        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 2) q.push({r, c});
                if (grid[r][c] == 1) fresh++;
            }

        if (fresh == 0) return 0;  

        int minutes = 0;

        while (!q.empty() && fresh > 0) {
            minutes++;
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                auto [r, c] = q.front(); q.pop();

                for (auto& d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (grid[nr][nc] != 1) continue;

                    grid[nr][nc] = 2; 
                    fresh--;
                    q.push({nr, nc});
                }
            }
        }

        return fresh == 0 ? minutes : -1;
    }
};
class Solution {
    const int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& visited,
             queue<pair<int,int>> q, int m, int n) {
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();

            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (visited[nr][nc]) continue;
                if (heights[nr][nc] < heights[r][c]) continue;

                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        vector<vector<bool>> pacific (m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        queue<pair<int,int>> pacQ, atlQ;

        for (int r = 0; r < m; r++) {
            pacific[r][0]    = true; pacQ.push({r, 0});
            atlantic[r][n-1] = true; atlQ.push({r, n-1});
        }
        for (int c = 0; c < n; c++) {
            pacific[0][c]    = true; pacQ.push({0, c});
            atlantic[m-1][c] = true; atlQ.push({m-1, c});
        }

        bfs(heights, pacific,  pacQ, m, n);
        bfs(heights, atlantic, atlQ, m, n);

        vector<vector<int>> result;
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                if (pacific[r][c] && atlantic[r][c])
                    result.push_back({r, c});

        return result;
    }
};
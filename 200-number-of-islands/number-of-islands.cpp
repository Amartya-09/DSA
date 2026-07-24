class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == '1') {
                    count++;
                    dfs(grid, r, c, m, n);
                }
            }
        }

        return count;
    }

private:
    void dfs(vector<vector<char>>& grid, int r, int c, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != '1')
            return;

        grid[r][c] = '0'; 

        dfs(grid, r+1, c, m, n);
        dfs(grid, r-1, c, m, n);
        dfs(grid, r, c+1, m, n);
        dfs(grid, r, c-1, m, n);
    }
};
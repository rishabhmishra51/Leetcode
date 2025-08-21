class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 1) 
            return 0;

        grid[i][j] = 0; // mark visited
        int count = 1;

        count += dfs(grid, i+1, j, m, n);
        count += dfs(grid, i-1, j, m, n);
        count += dfs(grid, i, j+1, m, n);
        count += dfs(grid, i, j-1, m, n);

        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int area = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int ans = dfs(grid, i, j, m, n);
                    area = max(area, ans);
                }
            }
        }
        return area;
    }
};

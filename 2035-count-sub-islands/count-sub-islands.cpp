class Solution {
    int m, n;
    vector<vector<int>> vis;

private:
    bool dfs(int r, int c, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vis[r][c] = 1;
        bool isValid = true;

        if (grid1[r][c] == 0) {
            isValid = false;
        }

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        for (int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr>=0 && nr<m && nc>=0 && nc<n && grid2[nr][nc] && !vis[nr][nc]) {
                if (!dfs(nr, nc, grid1, grid2)) {
                    isValid = false;
                }
            }
        }

        return isValid;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size(), n = grid1[0].size();

        vis = vector<vector<int>>(m, vector<int>(n, 0));
        int cnt = 0;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid2[i][j] && !vis[i][j] && dfs(i, j, grid1, grid2)) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
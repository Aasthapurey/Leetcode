class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        
        for (int col = 1; col < n; col++) {
            for (int row = 0; row < m; row++) {
                int relpace = INT_MAX;
                for (int i = max(0, row - 1); i < min(m, row + 2); i++) {
                    if (grid[i][col - 1] < grid[row][col]) {
                        relpace = grid[row][col];
                        res = col;
                        break;
                    }
                }
                grid[row][col] = relpace;
            }
            if(res != col) break;
        }

        return res;
    }
};
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {
        vector<vector<int>> ans;
        ans.push_back({rStart, cStart});
        int m = 1;
        int n = 2;
        while (ans.size() < rows * cols) {
            // 1 step inc east
            int i = 0;
            while (i < m) {
                cStart++;
                if (cStart >= 0 && cStart < cols && rStart >= 0 &&
                    rStart < rows) {
                    ans.push_back({rStart, cStart});
                }
                i++;
            }
            // 1 step dec south
            int j = 0;
            while (j < m) {
                rStart++;
                if (cStart >= 0 && cStart < cols && rStart >= 0 &&
                    rStart < rows) {
                    ans.push_back({rStart, cStart});
                }
                j++;
            }
            // 2 step dec west
            int k = 0;
            while (k < n) {
                cStart--;
                if (cStart >= 0 && cStart < cols && rStart >= 0 &&
                    rStart < rows) {
                    ans.push_back({rStart, cStart});
                }
                k++;
            }
            // 2 step inc north
            int l = 0;
            while (l < n) {
                rStart--;
                if (cStart >= 0 && cStart < cols && rStart >= 0 &&
                    rStart < rows) {
                    ans.push_back({rStart,cStart});
                }
                l++;
            }
            m = n + 1;
            n = m + 1;
        }
        return ans;
    }
};
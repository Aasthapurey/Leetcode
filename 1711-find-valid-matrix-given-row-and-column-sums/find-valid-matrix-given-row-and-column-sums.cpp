class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> res(rowSum.size(), vector<int>(colSum.size(), 0));
        for (int i = 0; i < rowSum.size(); i++) {
    int j = 0;
    while (j < colSum.size() && rowSum[i] > 0) {
        if (colSum[j] > 0) {
            if (colSum[j] >= rowSum[i]) {
                res[i][j] = rowSum[i];
                colSum[j] -= rowSum[i];
                rowSum[i] = 0;
            } else {
                res[i][j] = colSum[j];
                rowSum[i] -= colSum[j];
                colSum[j] = 0;
            }
        }
        j++;
    }
}

return res;

    }
};
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        
        vector<long long> prev(n);
        for (int i = 0; i < n; i++) {
            prev[i] = points[0][i];
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                prev[j] = max(prev[j], prev[j - 1] - 1);
            }
            
            for (int j = n - 2; j >= 0; j--) {
                prev[j] = max(prev[j], prev[j + 1] - 1);
            }

            for (int j = 0; j < n; j++) {
                prev[j] = points[i][j] + prev[j];
            }
        }
        
        return *max_element(prev.begin(), prev.end());
    }
};
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<int> arr(n, 0);
        int ele = -1;
        int cnt = 0;

        // Count the in-degree for each node
        for(int i = 0; i < m; i++) {
            arr[edges[i][1]]++;
        }

        // Find the node with zero in-degree
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0) {
                ele = i;
                cnt++;
            }
        }

        // If exactly one node has zero in-degree, return it
        if(cnt == 1) return ele;

        // Otherwise, return -1
        return -1;
    }
};
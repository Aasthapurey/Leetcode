class Solution {
public:
    int minimumDeletions(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n = s.length();
        vector<int> pre(n, 0), suff(n, 0);

        // Compute prefix sums for 'b' counts
        for (int i = 1; i < n; i++) 
            pre[i] = pre[i - 1] + (s[i - 1] == 'b');

        // Compute suffix sums for 'a' counts
        for (int i = n - 2; i >= 0; i--) 
            suff[i] = suff[i + 1] + (s[i + 1] == 'a');

        // Initialize answer to either all 'a's or all 'b's
        int ans = min(suff[0], pre[n - 1]); 
        
        // Find minimum deletions for each split point
        for (int i = 1; i < n; i++) 
            ans = min(ans, pre[i] + suff[i]);

        return ans;
    }
};
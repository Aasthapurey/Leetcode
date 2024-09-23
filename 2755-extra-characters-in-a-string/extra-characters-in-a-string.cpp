class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            dp[i] = dp[i + 1] + 1; 
            for (int j = 1; j <= n - i; ++j) {
                string substr = s.substr(i, j);
                if (dict.find(substr) != dict.end()) {
                    dp[i] = min(dp[i], dp[i + j]);
                }
            }
        }
        return dp[0];
    }
};
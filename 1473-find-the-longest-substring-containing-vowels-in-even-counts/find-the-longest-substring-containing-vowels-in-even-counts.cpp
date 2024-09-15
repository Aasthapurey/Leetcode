class Solution {
public:
    int findTheLongestSubstring(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // Note:
        // We need to return the longest substring which is containing the vowels even number of times.
        // Substring if we considered any start index and any end index
        // 0 <= startIndex <= endIndex <= s.size() - 1
        // s.size() -> n
        // n (n + 1) / 2 -- 4 * 5 / 2
        // abcd
        // a b c d
        // ab bc cd
        // abc bcd
        // abcd
        // (5 * ~) * (5 * ~ + 1) / 2
        // 25 * 10^10
        // General observations
        // In this question there is no constrain on the consonant character
        // Constraint is only for the vowel character
        // 1 ^ 1 or 0 ^ 0 --> 0
        // 1 ^ 0 or 0 ^ 1 --> 1
        // 1 ^ 1 ^ 1 ^ 1 --> 0
        // For each vowel we do need a parity
        // a e i o u
        // 1 2 4 8 16
        // 0 0 0 0 0
        // 0 0 0 0 1
        // 0 0 0 1 0
        // 0 0 1 0 0
        // Other property of XOR
        // x ^ 0 --> x
        // For every consonant character the parity would be 0
        vector<int> parity(26, 0);
        parity['a' - 'a'] = 1;
        parity['e' - 'a'] = 2;
        parity['i' - 'a'] = 4;
        parity['o' - 'a'] = 8;
        parity['u' - 'a'] = 16;
        // -1
        // e l e e t m i n i c o w o r o e p
        // 2 2 0 2 
        // a a ^ b a ^ b ^ c a ^ b ^ c ^ d
        // a = a ^ b ^ c ^ d
        // xor --> 0
        int n   = s.size();
        int xorVal = 0;
        int ans = 0;
        unordered_map<int, int> chkr;
        chkr[0] = -1;
        for(int i = 0 ; i < n ; i++){
            char ch = s[i];
            xorVal ^= parity[ch - 'a'];
            if(chkr.find(xorVal) == chkr.end()) chkr[xorVal] = i;
            ans = max(ans, i - chkr[xorVal]);
        }
        return ans;
    }
};
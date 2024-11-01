class Solution {
public:
    string makeFancyString(string s) {
        map<char, int> mp;
        char prev = '\0';
        string ans;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != prev) {
                mp[s[i]] = 0;
            }
            mp[s[i]]++;
            
            if (mp[s[i]] == 3) {
                mp[s[i]]--;
                continue;
            }
            
            ans.push_back(s[i]);
            prev = s[i];
        }
        
        return ans;
    }
};
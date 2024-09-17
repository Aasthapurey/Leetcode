class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp;
        istringstream ss1(s1);
        string w;
        while(ss1 >> w) 
        {
            mp[w]++;
        }
        istringstream ss2(s2);
        while(ss2 >> w)
        {
            mp[w]++;
        }

        vector<string>res;
        for(auto& [word , count] : mp)
        {
            if(count == 1)
            {
                res.push_back(word);
            }
        }
        return res;
    }
};
class Solution {
public:
    
    int minLength(string s) {

        vector<char> res; 
        
        for (char c : s) {
            if (!res.empty() && ((res.back() == 'A' && c == 'B') || (res.back() == 'C' && c == 'D'))) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        return res.size();
    }

};
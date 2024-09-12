class Solution {
public:
    bool sub(set<char> a,set<char> b){
        for(auto e:b){
                if(a.find(e)==a.end()){
                    return 0;
                }
        }
        return 1;
    }
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> s(allowed.begin(),allowed.end());
        int count=0;
        for(auto i:words){
            set<char> m(i.begin(),i.end());
            if(sub(s,m)){count++;}
            }
        return count;
    }
};
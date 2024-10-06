class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        s1.insert(s1.begin(),' '),s2.insert(s2.begin(),' '),s1.push_back(' '),s2.push_back(' ');
        int n = s1.size() , m = s2.size(),prefix_match = 0,suffix_match = 0,x = min(n,m),temp = x;
        for(int i=0;i<x;i++){
            if(s1[i] != s2[i])break;
            if(s1[i] == ' ' && s2[i] == ' ') prefix_match = i;
        }
        int i=n-1,j=m-1;
        while(temp--){
            if(s1[i] != s2[j])break;
            if(s1[i] == ' ' && s2[j] == ' ') suffix_match = x-1-temp;
            i--,j--;
        }
        return (prefix_match + suffix_match + 1 >= x);
    }
};
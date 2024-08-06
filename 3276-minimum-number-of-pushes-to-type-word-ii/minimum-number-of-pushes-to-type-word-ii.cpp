static const int fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    return 0;
}();
class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        vector<int>v(26,0);
        for(int i=0;i<n;i++){
            v[word[i]-'a']++;
        }
        sort(v.rbegin(),v.rend());
        int ans=0;
        for(int i=0;i<26;i++){
            ans+=(v[i])*((i/8)+1);
        }
        return ans;
    }
};
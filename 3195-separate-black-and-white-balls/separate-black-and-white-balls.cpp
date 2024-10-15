class Solution {
public:
    long long minimumSteps(string s) {
        long long n=s.size();
        long long onecount=0;
        long long swaps=0;
        for(long long i=0;i<n;i++){
            if(s[i]=='1') onecount++;
            else swaps+=onecount;
        }
        return swaps;
    }
};
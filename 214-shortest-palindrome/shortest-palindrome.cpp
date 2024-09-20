class Solution {
public:
    string shortestPalindrome(string s) {
        if(s == "") return s;
        int n = s.size();
        vector<long long> pref(n+1);
        vector<long long> suff(n+2);
        vector<long long> pow(n+1);

        const int M = 1e9+7;
        pow[0] = 1;
        for(int i = 1; i <= n; i++){
            pow[i] = (pow[i-1] * 31) % M;
        }
        for(int i = 0; i < n; i++){
            pref[i+1] = (pref[i] + (s[i]-'a'+1) * pow[i]) % M;
        }
        for(int i = n; i >= 1; i--){
            suff[i] = (suff[i+1] + (s[i-1]-'a'+1) * pow[n-i]) % M;
        }

        int s1 = 1, e1 = (n+1)/2;
        int s2 = n/2+1, e2 = n;
        int L;
        for(L = n; L < 2*n; L++){
            int mul = n-e2;
            if((((pref[e1] - pref[s1-1] + M) % M) * pow[mul]) % M == (suff[s2] - suff[e2+1] + M) % M){
                break;
            }
            if(L % 2 == 0) s2--, e2--;
            else e1--, e2--;
        }
        reverse(s.begin(), s.end());
        for(int i = 0; i < L-n; i++){
            s += '.';
        }

        for(int i = 0; i < L/2; i++){
            if(s[i] != s[L-1-i]) s[L-1-i] = s[i];
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
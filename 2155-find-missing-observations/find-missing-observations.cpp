class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int old_sum=0;
        for(int i=0;i<m;i++){
            old_sum+=rolls[i];
        }
        int new_sum=mean*(n+m);
        int diff= new_sum-old_sum;
        //diff minimum n hoga kyoki min val dice mei 1 hai
        // maximum n*6 hoga kyoki max val dice mei 6 hai
        if(diff <n || diff>6*n){
            return {};
        }
        vector<int> res(n,diff/n);
        int rem=diff % n;
        for(int i=0;i<rem;i++){
            res[i]++;
        }
        return res;
    }
};
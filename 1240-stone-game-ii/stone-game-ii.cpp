class Solution {
public:
    map<vector<int>,int> store;
    int getS(vector<int>& piles,int i,int M,bool at){
        // cout << "i : " << i << " M : " << M << " at : " << at << endl;
        if(i == piles.size()) return 0;
        if(store.find({i,M,at}) != store.end()){
            return store[{i,M,at}];
        }
        int sum = 0;
        int res = at ? INT_MIN : INT_MAX;
        for(int j=1;j<=2*M;j++){
            if(i+j-1 >= piles.size()) break;
            sum+=piles[i+j-1];
            if(at){
                res = max(res,sum + getS(piles,i+j,max(j,M),!at));
            }else{
                res = min(res,getS(piles,i+j,max(j,M),!at));
            }
        }
        return store[{i,M,at}]=res;
    }
    int stoneGameII(vector<int>& piles) {
        store.clear();
        return getS(piles,0,1,true);
    }
};
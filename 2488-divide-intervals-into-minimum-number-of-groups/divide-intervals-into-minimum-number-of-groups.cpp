class Solution {
public:
vector<int> bit;
int  N;
    int sum(int id){
        int ans = 0;
        while(id > 0){
            ans += bit[id];
            id = (id - (id & -id));
        }
        return ans;
    }
    void update(int id, int x){

        while(id <= N){
            bit[id] += x;
            id = (id + (id & -id));
        }
    }
    void updateRange(int l, int r){
        update(l,1);
        update(r+1,-1);
    }
    int minGroups(vector<vector<int>>& a) {
        
        for(int i=0;i<a.size();i++){
            N = max(N, a[i][1]);
        }
        bit = vector<int> (N+2,0);

        for(int i=0;i<a.size();i++){
            updateRange(a[i][0],a[i][1]);
        }

        int ans = 0;
        for(int i =1;i<bit.size();i++){
            ans = max(ans, sum(i));
        }

        return ans;
    }
};
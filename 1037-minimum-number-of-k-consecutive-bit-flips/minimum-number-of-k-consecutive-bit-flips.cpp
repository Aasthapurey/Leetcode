class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int> q;
        int ans=0,n=nums.size();
        for(int i=0;i<=n-k;i++){
            if((nums[i]==1 && (q.size() & 1)) || (nums[i]==0 && !(q.size() & 1))){
                    q.push(i+k-1);
                    ans++;
            }
            if(q.front()==i){
                q.pop();
            }
        }
        for(int i=n-k+1;i<n;i++){
            if((nums[i]==1 && (q.size() & 1)) || (nums[i]==0 && !(q.size() & 1))){
                return -1;
            }
            if(q.front()==i) q.pop();
        }
        return ans;
    }
};
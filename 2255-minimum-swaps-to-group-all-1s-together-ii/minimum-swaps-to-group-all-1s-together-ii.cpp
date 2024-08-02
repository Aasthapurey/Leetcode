class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ans=INT_MAX,ones=0,temp_ones=0,j=0;
        ones=accumulate(nums.begin(),nums.end(),0);
        if(ones==0) return 0;
        int i=ones;
        temp_ones=accumulate(nums.begin(),nums.begin()+ones,0);
        ans=min(ans,ones-temp_ones);
        while(true){
            if(i%nums.size()==ones-1) break;
             temp_ones+=nums[i%nums.size()];
             temp_ones-=nums[j%nums.size()];
             ans=min(ans,ones-temp_ones);
             i++,j++;
        }
        return ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
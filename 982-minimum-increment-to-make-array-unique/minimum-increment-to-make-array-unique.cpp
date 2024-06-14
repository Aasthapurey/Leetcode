class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int mini=*(min_element(nums.begin(),nums.end()));

        int st=mini;

        sort(nums.begin(),nums.end());

        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;){
            if(st<nums[i])
            st++;
            else{
               ans+=(st-nums[i]);
               st++;
               i++;
            }
        }

        return ans;
    }
};
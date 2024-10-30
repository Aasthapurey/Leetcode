class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix = buildMountainSideLIS(nums);
        reverse(nums.begin(), nums.end());
        vector<int> sufix = buildMountainSideLIS(nums);
        
        reverse(sufix.begin(), sufix.end());
        
        int sidelis = 0;
        for (int i = 1; i < n; i++) {
            if (prefix[i] > 1 && sufix[i] > 1)
                sidelis = max(sidelis, prefix[i] + sufix[i] - 1);
        }
        return n - sidelis;
    }
    
    vector<int> buildMountainSideLIS(vector<int>& nums) {
        vector<int> lis(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }
        return lis;
    }
};
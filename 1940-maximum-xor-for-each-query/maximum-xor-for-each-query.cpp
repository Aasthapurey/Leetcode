class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int max = (1 << maximumBit) - 1;  
        vector<int> prefixor(n);
        vector<int> ans;

        prefixor[0] = nums[0];
        
        for (int i = 1; i < n; i++) {
            prefixor[i] = prefixor[i - 1] ^ nums[i];
        }

        for (int i = 0; i < n; i++) {
            ans.push_back(prefixor[n - i - 1] ^ max);
        }
        
        return ans;
    }
};
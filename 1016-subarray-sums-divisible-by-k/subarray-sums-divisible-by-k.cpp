class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int res = 0;          
        int prefix = 0;       
        vector<int> arr(k, 0); 
        arr[0] = 1;           

        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i] % k + k) % k;
            res += arr[prefix];
            arr[prefix]++;
        }
        return res; 
    }
};
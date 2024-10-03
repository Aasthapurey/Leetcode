class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long int total_sum = 0;
        for (auto& num : nums) {
            total_sum += num; 
        }
        if(p >  total_sum) {
            return -1;
        }
        long long int target = total_sum % p;

        if(target == 0) {
            return 0;
        }

        unordered_map<int, int> mp;
        mp[0] = -1; 
        long long int cur_sum = 0;
        int mini = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            cur_sum += nums[i];
            int cur_rem = cur_sum % p;
            int rem = (cur_rem - target + p) % p;

            if (mp.find(rem) != mp.end()) {
                int sub = i - mp[rem];
                mini = min(mini, sub);
            }

            mp[cur_rem] = i;
        }

        return mini == nums.size() ? -1 : mini;
    }
};
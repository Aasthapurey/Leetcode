class Solution {
public:
    int cnt(int n) { 
        bitset<32> binary(n);  
        return binary.count(); 
    }

    bool canSortArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int mx = nums[0];
        int mn = nums[0];
        int setBits = cnt(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            if (setBits == cnt(nums[i])) {
                mx = max(mx, nums[i]);
                mn = min(mn, nums[i]);
            } else {
                if (mn <maxi) {
                    return false;
                }
               maxi = mx;
                setBits = cnt(nums[i]);
                mn = nums[i];
                mx = nums[i];
            }
        }

        return mn > maxi;
    }
};
class Solution {
public:
    int replacedNumber(int i, int k, vector<int>& nums, int dir) {
        if (k < 0) {
            k = abs(k);
            dir *= -1;
        }
        int n = nums.size();
        int sum = 0;
        while (k--) {
            i = (i + dir + n)% n ;
            sum += nums[i];
        }
        return sum;
    }
    vector<int> decrypt(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, 0);
        if (k == 0) return ans;

        for (int i = 0; i < n; i++) {
            ans[i] = replacedNumber(i, k, nums, 1);
        }
        return ans;
    }
};
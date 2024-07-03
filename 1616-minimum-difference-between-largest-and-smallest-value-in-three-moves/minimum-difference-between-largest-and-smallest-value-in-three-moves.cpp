class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();

        if (n <= 4) {
            return 0;
        }

        sort(begin(nums), end(nums));
        int minDiff = INT_MAX;

        minDiff = min(minDiff, (nums[n-4] - nums[0]));
        minDiff = min(minDiff, (nums[n-3] - nums[1]));
        minDiff = min(minDiff, (nums[n-2] - nums[2]));
        minDiff = min(minDiff, (nums[n-1] - nums[3]));

        return minDiff;
    }
};
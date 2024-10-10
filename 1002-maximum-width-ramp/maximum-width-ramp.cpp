class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int size = nums.size(), maxWidth = 0;
        vector<int> maxFrmRight(size);
        for (int indx = size - 1; indx > -1; indx--) {
            int prevMax = (indx + 1 < size) ? maxFrmRight[indx + 1] : 0;
            maxFrmRight[indx] = max(prevMax, nums[indx]);
        }
        int prevIndx = 0;
        for (int currIndx = 0; currIndx < size; currIndx++) {
            while (prevIndx < currIndx && maxFrmRight[currIndx] < nums[prevIndx]) prevIndx++;
            maxWidth = max(maxWidth, currIndx - prevIndx);
        }
        return maxWidth;
    }
};
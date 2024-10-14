class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> maxScrQ; 
        for (int num : nums) {
            maxScrQ.push(num);
        }
        long long maxScore = 0;
        while (k-- > 0) {
            int maxContri = maxScrQ.top();
            maxScrQ.pop();
            maxScore += maxContri;
            maxContri = (maxContri + 2) / 3;
            if (maxContri > 0) {
                maxScrQ.push(maxContri);
            }
        }
        return maxScore;
    }
};

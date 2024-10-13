class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        int k=nums.size();
        vector<int> track(k,0);
        vector<bool> fin(k,1);
        vector<int> ans(2,0);
        ans[0]= -100000;
        ans[1]= 100000;
        bool m=1;
        while(m)
        {
            int a=100000,b= -100000;
            int c=0;
            for(int i=0; i<k; i++)
            {
                if(nums[i][track[i]] < a)
                {
                    a = nums[i][track[i]];
                    c = i;
                }
                b = max(b,nums[i][track[i]]);
            }
            track[c]++;
            if(track[c] >= nums[c].size()) m=0;
            if(ans[1]-ans[0] > b-a)
            {
                ans[0]=a;
                ans[1]=b;
            }
        }
        return ans;
    }
};
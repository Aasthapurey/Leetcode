class Solution {
public:
    int minBitFlips(int A, int B) {
        int C=A^B;
        int ans=0;
        while(C)
        {   
            if(C&1)
                ans++;
            C = C >> 1;
        }
        return ans;
    }
};
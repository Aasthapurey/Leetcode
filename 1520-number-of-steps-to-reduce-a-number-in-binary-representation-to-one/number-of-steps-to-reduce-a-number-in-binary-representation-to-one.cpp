
class Solution {
public:
    int numSteps(string s) {
        int n=s.size(),ans=0,carry=0;
        for(int i=s.size()-1;i>=1;i--){
            if((s[i]-'0'+carry)%2==1){
                ans+=2;
                carry=1;
            }
            else{
                ans+=1;
            }
        }
        return ans+carry;
    }
};


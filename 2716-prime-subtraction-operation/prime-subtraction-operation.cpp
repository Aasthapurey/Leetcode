class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        //here num range is bw [1,1000]
        vector<bool>is_prime(1001,true);
        for(int i=2;i<=1000;i++){
            int temp=i+i;
            while(temp<is_prime.size()){
                is_prime[temp]=false;
            temp+=i;
            }
        }
        // for(int i=2;i<is_prime.size();i++){
        //     if(is_prime[i]) cout<<i<<" - is prime"<<endl;
        // }
        //we will use brute force + greedy i.e for each no we will make its min possbile value by subractig with the highest prime that make it strictly increasing
        int prev=-1;
        for(int i=0;i<nums.size();i++){
            for(int j=nums[i]-1;j>1;j--){
                if(is_prime[j] && nums[i]-j>prev) {
            // cout<<nums[i]<<j<<endl;
                    nums[i]-=j;
                    break;
                }
            }
                    prev=nums[i];
        }
        bool ans =true;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>=nums[i+1]){
                ans=false;
                break;
            }
        }
        return ans;
    }
};
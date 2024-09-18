class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans="";
        vector<string>str;
        // create a string array of the elements in the nums array
        for(int i=0;i<nums.size();i++){
            str.push_back(to_string(nums[i]));
        }        
        // sort the created string array with the compare function this compare functions sorts the elements ont he basis of combination that they form
        
        sort(str.begin(),str.end(),[](string &a,string &b){
            return a+b>b+a;
        });
// if irst element of this created array is "0" then all the elements ahead are "0" so we return "0";
        if(str[0]=="0"){
            return "0";
        }
// else we forma string out of created array that holds desired answer and return it.
        string result;
        for(string s:str){
            ans+=s;
        }
        return ans;
    }
};
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
static int x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();
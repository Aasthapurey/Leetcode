class Solution {
public:
int upper_bound(vector<int>&nums,int target,int start){
int end=nums.size();
while(start<end){
  int mid=start+(end-start)/2;
  if(nums[mid]<=target) start=mid+1;
  else end=mid;
}
return end-1;
}
int lower_bound(vector<int>&nums,int target,int start){
int end=nums.size();
while(start<end){
 int mid=start+(end-start)/2;
  if(nums[mid]<target) start=mid+1;
  else end=mid;
}
return end;
}
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
        int lower1=lower-nums[i];
        int upper1=upper-nums[i];
        int start=lower_bound(nums,lower1,i+1);
        int end=upper_bound(nums,upper1,i+1);
         ans+=max(0,end-start+1);
        }
        return ans;
    }
};
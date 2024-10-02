class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
     set<int>s(arr.begin(),arr.end());
     map<int,int>mp;
     int i=1;
     for(auto it:s) mp[it]=i++;
     for(auto &it:arr) it=mp[it];
     return arr;   
    }
};
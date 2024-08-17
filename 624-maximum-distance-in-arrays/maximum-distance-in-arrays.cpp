class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = arrays[0][0]; // first element is the least element of the array, as array is sorted
        int maxi = arrays[0].back(); // last element is the max element in the array as array is sorted
        int maxDist=0; //it changes when it gets higher element than itself
        for(int i=1;i<arrays.size();i++){
            //the maximum distance will be abs difference between maximum element and minimum element
            maxDist = max(maxDist,abs(maxi-arrays[i][0])); 
            maxDist = max(maxDist,abs(mini-arrays[i].back()));
            // change the maxi and mini to current array element's maximum and minimum elements
            maxi = max(arrays[i].back(),maxi);
            mini = min(arrays[i][0],mini);
        }
        // return the maximum element
        return maxDist;
    }
};
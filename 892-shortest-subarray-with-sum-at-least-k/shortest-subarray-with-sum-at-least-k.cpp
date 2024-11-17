class Solution {
public:
    void updateTree(vector<int>& segmentTree, int leafSize, int index, int val){
        int start = index + leafSize;
        segmentTree[start] = val;
        while (start >= 1){
            int parent = start/2;
            int neighbour = parent * 2;
            if (neighbour == start){
                neighbour += 1;
            }
            segmentTree[parent] = max(segmentTree[start], segmentTree[neighbour]);
            start = parent;
        }
    }

    int maxRange(vector<int>& segmentTree, int leafSize, int from, int to){
        int left = leafSize + from;
        int right = leafSize + to;


        int maxIndex = -1;
        while (left < right){
            if (left % 2 == 1){
                maxIndex = max(maxIndex, segmentTree[left]);
                left += 1;
            }
            left /= 2;

            if (right % 2 == 0){
                maxIndex = max(maxIndex, segmentTree[right]);
                right -= 1;
            }
            right /= 2;
        } 

        if (left == right){
            maxIndex = max(maxIndex, segmentTree[left]);
        }

        return maxIndex;
    }

    int shortestSubarray(vector<int>& nums, int k) {
        // Create prefix sum
        vector<long long> preFix(nums.size(), 0);
        preFix[0] = nums[0];
        if (nums[0] >= k){
            return 1;
        }

        int mini = nums.size() + 2;
        for (int i=1; i < nums.size(); i++){
            preFix[i] = preFix[i-1] + nums[i];
            if (nums[i] >= k){
                return 1;
            }

            if (preFix[i] >= k){
                mini = min(mini, i + 1);
            }
        }

        // Sort it to use the index for index compression
        unordered_set<long long> check;
        vector<long long> sortedPreFix;
        for (auto& num: preFix){
            if (check.count(num) == 0){
                sortedPreFix.push_back(num);
                check.insert(num);
            }
        }

        sort(sortedPreFix.begin(), sortedPreFix.end());
        unordered_map<long long, int> mapIndex;
        for (int i=0; i < sortedPreFix.size(); i++){
            mapIndex[sortedPreFix[i]] = i; 
        } 
        

        // Make a segment tree
        int leafSize = 1;
        while (leafSize < sortedPreFix.size()){
            leafSize *= 2;
        }

        vector<int> segmentTree(2 * leafSize, -1);
        updateTree(segmentTree, leafSize, mapIndex[preFix[0]], 0);

        for (int i=1; i < preFix.size(); i++){
            long long lBound = preFix[i] - k;
            auto upper = upper_bound(sortedPreFix.begin(), sortedPreFix.end(), lBound);
            int index = distance(sortedPreFix.begin(), upper);
            if (index == 0){
                updateTree(segmentTree, leafSize, mapIndex[preFix[i]], i);
                continue;
            }

            int closest = maxRange(segmentTree, leafSize, 0, index - 1);
            if (closest != -1){
                // cout << i << " " << closest << endl;
                // cout << preFix[i] << " " << preFix[closest] << endl;
                mini = min(mini, i - closest);
            }
            updateTree(segmentTree, leafSize, mapIndex[preFix[i]], i);
        }
        
        if (mini == nums.size() + 2){
            return -1;
        }
        return mini;


    }
};
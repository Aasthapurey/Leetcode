class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];  
        });
        vector<int> maxBeauty(items.size(), 0);
        maxBeauty[0] = items[0][1];  
        for (int i = 1; i < items.size(); i++) {
            maxBeauty[i] = max(maxBeauty[i - 1], items[i][1]);
        }
        vector<int> result;
        for (int price : queries) {
            int idx = binary_search(items, price);  
            result.push_back(idx == -1 ? 0 : maxBeauty[idx]);  
        }
        return result;
    }
private:
    int binary_search(const vector<vector<int>>& items, int queryPrice) {
        int low = 0, high = items.size() - 1;
        int answer = -1;  
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (items[mid][0] <= queryPrice) {  
                answer = mid;
                low = mid + 1;  
            } else {
                high = mid - 1; 
            }
        }
        return answer;
    }
};
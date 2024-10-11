class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        for(int i = 0; i < n; i++) {
            times[i].push_back(i); // Append the friend's index to the times array
        }
        
        // Sort friends based on arrival times
        sort(times.begin(), times.end());

        // Min-heap to keep track of available chairs
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        for (int i = 0; i < n; ++i) {
            availableChairs.push(i); // Initially, all chairs are available
        }

        // Min-heap to track when friends leave and which chairs are freed
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leavingQueue;
        
        for(auto &t : times) {
            int arrival = t[0];
            int departure = t[1];
            int idx = t[2];

            // Free chairs for friends who have left before the current arrival time
            while (!leavingQueue.empty() && leavingQueue.top().first <= arrival) {
                availableChairs.push(leavingQueue.top().second);
                leavingQueue.pop();
            }

            // Assign the smallest available chair
            int chair = availableChairs.top();
            availableChairs.pop();

            // If this is the target friend, return the chair number
            if (idx == targetFriend) {
                return chair;
            }

            // Record when this friend leaves and the chair becomes available
            leavingQueue.push({departure, chair});
        }
        
        return -1; // In case we don't find the target friend (shouldn't happen with valid input)
    }
};
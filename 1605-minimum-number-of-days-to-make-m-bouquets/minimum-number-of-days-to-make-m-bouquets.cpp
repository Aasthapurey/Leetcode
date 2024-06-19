#include <vector>
#include <algorithm>

class Solution {
public:
    int countBouquets(int mid, std::vector<int>& bloomDay, int k) {
        int bouquets = 0, flowers = 0;
        for (int day : bloomDay) {
            if (day <= mid) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return bouquets;
    }

    int minDays(std::vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m > n / k) return -1;  

        int left = *std::min_element(bloomDay.begin(), bloomDay.end());
        int right = *std::max_element(bloomDay.begin(), bloomDay.end());
        int answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (countBouquets(mid, bloomDay, k) >= m) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }
};
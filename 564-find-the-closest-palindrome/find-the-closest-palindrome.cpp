#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class Solution {
public:
    std::string nearestPalindromic(std::string n) {
        int len = n.size();
        
        
        if (n == "1") return "0";
        if (n == "0") return "1";

        
        std::vector<long long> candidates;
        long long num = stoll(n); 
        
        
        std::string nine(len - 1, '9');
        if (!nine.empty()) candidates.push_back(stoll(nine));

        
        std::string one(len + 1, '0');
        one[0] = '1';
        one[len] = '1';
        candidates.push_back(stoll(one));
        
        
        std::string prefix = n.substr(0, (len + 1) / 2);
        long long prefix_num = stoll(prefix);

        
        for (long long i = -1; i <= 1; ++i) {
            std::string candidate = std::to_string(prefix_num + i);
            std::string mirrored = candidate + std::string(candidate.rbegin() + (len % 2), candidate.rend());
            if (!mirrored.empty()) candidates.push_back(stoll(mirrored));
        }

        
        long long closest = -1;
        for (long long candidate : candidates) {
            if (candidate != num) {
                if (closest == -1 || std::abs(candidate - num) < std::abs(closest - num) ||
                    (std::abs(candidate - num) == std::abs(closest - num) && candidate < closest)) {
                    closest = candidate;
                }
            }
        }

        return std::to_string(closest);
    }
};  
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Edge case: If s1 is longer than s2, return false
        if (s1.size() > s2.size()) return false;

        // Frequency arrays for s1 and the first window in s2
        vector<int> s1Freq(26, 0), windowFreq(26, 0);

        // Fill the frequency array for s1 and the first window of s2
        for (int i = 0; i < s1.size(); i++) {
            s1Freq[s1[i] - 'a']++;
            windowFreq[s2[i] - 'a']++;
        }

        // Check if the first window matches
        if (s1Freq == windowFreq) return true;

        // Slide the window across s2
        for (int i = s1.size(); i < s2.size(); i++) {
            // Add the new character and remove the old character from the window
            windowFreq[s2[i] - 'a']++;
            windowFreq[s2[i - s1.size()] - 'a']--;

            // Check if the current window matches
            if (s1Freq == windowFreq) return true;
        }

        return false;
    }
};
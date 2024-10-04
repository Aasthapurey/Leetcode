class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        long long total = 0;
        long long targetSum = skill[0] + skill[skill.size() - 1];

        for (int i = 0, j = skill.size() - 1; i < j; ++i, --j) {
            if (skill[i] + skill[j] != targetSum) {
                return -1;
            }
            total += static_cast<long long>(skill[i]) *
                     skill[j]; // Use long long for multiplication
        }
        return total;
    }
};
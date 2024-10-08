class Solution {
public:
    long long total_numbers(long long curr, long long next, long long n) {
        long long ans = 0;
        while (curr <= n) {
            ans += min(next, n + 1) - curr;
            curr *= 10;
            next *= 10;
        }
        return ans;
    }
    
    int findKthNumber(int n, int k) {
        long long curr = 1;
        k--;  // Decrement k as we start with 1
        while (k > 0) {
            long long count = total_numbers(curr, curr + 1, n);
            if (count <= k) {
                k -= count;
                curr++;  // Skip this subtree
            } else {
                k--;
                curr *= 10;  // Move deeper into the tree
            }
        }
        return (int)curr;
    }
};
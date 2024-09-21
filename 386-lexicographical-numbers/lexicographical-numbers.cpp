class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int num = 1;  // Start with the smallest number

        // Generate all numbers from 1 to n in lexicographical order
        for (int i = 0; i < n; i++) {
            result.push_back(num);

            if (num * 10 <= n) {
                // If appending a 0 keeps us within n, do it
                // This is equivalent to going to the leftmost child in the number tree
                num *= 10;
            } else {
                // If we can't append 0, we need to increment

                // Keep removing the last digit until we can increment
                // This happens when we're at the end of a branch (num % 10 == 9)
                // or when we've reached n
                while (num % 10 == 9 || num == n) {
                    num /= 10;  // Go up one level in the number tree
                }

                num++;  // Move to the next sibling in the number tree
            }
        }
        return result;
    }
};
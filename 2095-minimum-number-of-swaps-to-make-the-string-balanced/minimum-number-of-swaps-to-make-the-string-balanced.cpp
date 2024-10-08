class Solution {
public:
    int minSwaps(string s) {
        int open = 0; // Track unbalanced opening brackets
        
        // Traverse the string
        for(auto c : s) {
            if (c == '[') 
                open++; // Found an opening bracket, increase the count
            else if (open > 0) 
                open--; // Found a closing bracket, balance it with an opening bracket if available
        }
        
        // Return the minimum number of swaps needed to balance the remaining unbalanced opening brackets
        return (open + 1) / 2;
    }
};
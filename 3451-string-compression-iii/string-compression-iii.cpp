class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int n = word.size();
        for(int i = 0; i < n; i++)
        {
            int j = i + 1;
            while(j < n && word[j] == word[i])
            {
                j++;
            }
            int size = j - i;
            while(size > 0)
            {
                int minSize = min(9, size);
                comp.push_back(minSize + '0');
                comp.push_back(word[i]);
                size = size - minSize;
            }
            i = j - 1;
        }
        return comp;
    }
};
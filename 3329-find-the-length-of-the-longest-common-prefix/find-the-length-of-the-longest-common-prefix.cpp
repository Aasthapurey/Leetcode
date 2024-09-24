class Solution {
    class Node {
    public:
        vector<Node*> nxt;
        Node() { nxt.assign(10, NULL); }  // 10 for digits 0-9
        friend class Trie;
    };
    
    class Trie {
        Node* head;

    public:
        Trie() { head = new Node(); }

        // Adds a string (integer) to the Trie
        void add(string str) {
            Node* temp = head;
            for (char ch : str) {
                if (!temp->nxt[ch - '0'])
                    temp->nxt[ch - '0'] = new Node();
                temp = temp->nxt[ch - '0'];
            }
        }

        // Finds the longest matching prefix for a given string
        int find(string str) {
            Node* temp = head;
            int n = str.length();
            for (int i = 0; i < n; i++) {
                if (!temp->nxt[str[i] - '0'])
                    return i;  // return length of matching prefix
                temp = temp->nxt[str[i] - '0'];
            }
            return n;  // full string is a matching prefix
        }
    };

public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* node = new Trie();

        // Add all integers from arr1 to the Trie
        for (auto& it : arr1)
            node->add(to_string(it));

        int ans = 0;

        // Find the longest common prefix for each integer in arr2
        for (auto& it : arr2)
            ans = max(ans, node->find(to_string(it)));

        return ans;
    }
};
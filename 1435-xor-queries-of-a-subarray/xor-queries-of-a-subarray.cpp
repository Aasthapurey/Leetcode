class Solution {
public:
    std::vector<int> xorQueries(std::vector<int>& arr,
                                std::vector<std::vector<int>>& queries) {
        int n = arr.size();
        std::vector<int> pre(n);
        pre[0] = arr[0];

        // Compute prefix XOR array
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] ^ arr[i];
        }

        std::vector<int> res;

        // Answer each query
        for (const auto& query : queries) {
            int left = query[0], right = query[1];
            if (left == 0) {
                res.push_back(pre[right]);
            } else {
                res.push_back(pre[right] ^ pre[left - 1]);
            }
        }

        return res;
    }
};
class Solution {
public:
    int greaterSum = 0;

    // Converts the BST to a Greater Sum Tree
    TreeNode* bstToGst(TreeNode* root) {
        reverseInorder(root);
        return root;
    }

private:
    // Performs a reverse inorder traversal to calculate greater sums
    void reverseInorder(TreeNode* root) {
        if (root == nullptr)
            return;

        // Traverse right subtree first
        reverseInorder(root->right);

        // Update the current node's value with the greater sum
        greaterSum += root->val;
        root->val = greaterSum;

        // Traverse left subtree
        reverseInorder(root->left);
    }
};

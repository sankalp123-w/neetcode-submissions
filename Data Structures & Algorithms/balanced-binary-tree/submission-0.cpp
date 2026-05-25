/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int checkHeight(TreeNode* root) {
        if (root == nullptr) return 0;

        // Check the height of the left subtree
        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1) return -1; // Left subtree is already imbalanced

        // Check the height of the right subtree
        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1) return -1; // Right subtree is already imbalanced

        // If the current node is imbalanced, return -1
        if (std::abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        // Otherwise, return the actual height of this node
        return std::max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        // If checkHeight doesn't return -1, the tree is balanced
        return checkHeight(root) != -1;
    }
};

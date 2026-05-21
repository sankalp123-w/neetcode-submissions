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
    int maxDiameter = 0;

    // This helper function returns the height of the tree
    // while updating the global maxDiameter along the way.
    int calculateHeight(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);

        // The longest path passing through the current node
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        // Return the height of the current subtree to the parent
        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0; // Reset for each call
        calculateHeight(root);
        return maxDiameter;
    }
};

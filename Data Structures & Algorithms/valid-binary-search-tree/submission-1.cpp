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
TreeNode* prev = nullptr; // Keeps track of the node we just visited

    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;

        // 1. Visit Left Subtree
        if (!isValidBST(root->left)) return false;

        // 2. Check current node: Must be greater than the previous node
        if (prev != nullptr && root->val <= prev->val) {
            return false;
        }
        prev = root; // Update prev to current node

        // 3. Visit Right Subtree
        return isValidBST(root->right);
    }
};

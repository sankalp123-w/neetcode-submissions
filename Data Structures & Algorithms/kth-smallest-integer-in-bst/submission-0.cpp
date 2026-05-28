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
int countNodes(TreeNode* n) {
    if (n == nullptr) return 0;
    return 1 + countNodes(n->left) + countNodes(n->right);
}

int kthSmallest(TreeNode* root, int k) {
    int leftSize = countNodes(root->left);

    if (k == leftSize + 1) {
        return root->val; // This is the k-th element!
    } else if (k <= leftSize) {
        return kthSmallest(root->left, k); // It's in the left side
    } else {
        // It's in the right side, but we skip the left side and the root
        return kthSmallest(root->right, k - leftSize - 1);
    }
}
};

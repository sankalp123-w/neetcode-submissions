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
// We set a default value of INT_MIN for the first call
    int goodNodes(TreeNode* root, int curmax = INT_MIN) {
        if (root == nullptr) return 0;
        
        int count = 0;
        
        // Check if current node is good
        if (root->val >= curmax) {
            count = 1;
            curmax = root->val; // Update curmax for the children
        }
        
        // Pass the updated curmax down to the left and right children
        return count + goodNodes(root->left, curmax) + goodNodes(root->right, curmax);
    }
};

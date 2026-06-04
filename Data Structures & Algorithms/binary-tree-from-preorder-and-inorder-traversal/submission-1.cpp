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
unordered_map<int, int> inMap; // Maps value -> index for O(1) lookups

    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd, 
                     vector<int>& inorder, int inStart, int inEnd) {
        
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        // The first element in preorder is always the root
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Find where this root sits in inorder
        int inRootIdx = inMap[root->val];
        int numsLeft = inRootIdx - inStart; // Size of left subtree

        // Recursively build left and right subtrees using boundaries
        root->left = helper(preorder, preStart + 1, preStart + numsLeft, 
                            inorder, inStart, inRootIdx - 1);
                            
        root->right = helper(preorder, preStart + numsLeft + 1, preEnd, 
                             inorder, inRootIdx + 1, inEnd);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inMap.clear();
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};

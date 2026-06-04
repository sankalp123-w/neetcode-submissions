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
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty() || inorder.empty()) return nullptr;
    TreeNode* root = new TreeNode(preorder[0]);
     auto it = find(inorder.begin(), inorder.end(),preorder[0]);
    // Calculate the size of the left subtree
    int leftSubtreeSize = distance(inorder.begin(), it);
   // 3. Slice vectors for the Left Subtree
    // Preorder left: skip the root, take 'leftSubtreeSize' elements
    vector<int> spl(preorder.begin() + 1, preorder.begin() + 1 + leftSubtreeSize);
    // Inorder left: everything from start up to 'it'
    vector<int> sil(inorder.begin(), it);
    TreeNode* left = buildTree (spl,sil);
    vector<int> spr(preorder.begin() + 1 + leftSubtreeSize, preorder.end());
    // Inorder right: everything after 'it' (skip the root element itself)
    vector<int> sir(it + 1, inorder.end());
    TreeNode* right = buildTree (spr,sir);
    root->left = left;
    root->right = right;
    return root;
    }
};

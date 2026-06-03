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
    int res=0;
    int dfs(TreeNode* root){
    if (root ==nullptr) return 0;
     int leftsum = dfs(root->left);
     int rightsum = dfs(root->right);
     leftsum = max(leftsum,0);
     rightsum = max(rightsum,0);
     res = max(root->val+leftsum+rightsum,res);
     return max(root->val+leftsum, root->val+rightsum);
    }
    int maxPathSum(TreeNode* root) {
    res = root->val;
    dfs(root);
    return res;
    }
};

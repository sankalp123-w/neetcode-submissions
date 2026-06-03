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

    int dfs(TreeNode* root,int & res){
    if (root ==nullptr) return 0;
     int leftsum = dfs(root->left,res);
     int rightsum = dfs(root->right,res);
     leftsum = max(leftsum,0);
     rightsum = max(rightsum,0);
     res = max(root->val+leftsum+rightsum,res);
     return max(root->val+leftsum, root->val+rightsum);
    }
    int maxPathSum(TreeNode* root) {
    int res = root->val;
    dfs(root,res);
    return res;
    }
};

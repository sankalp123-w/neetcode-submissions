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

class Codec {
public:

void serializeDFS(TreeNode* root, stringstream& ss) {
        if (!root) {
            ss << "#,";
            return;
        }
        // Append current value and delimiter
        ss << root->val << ",";
        // Recurse left and right
        serializeDFS(root->left, ss);
        serializeDFS(root->right, ss);
    }
    TreeNode* deserializeDFS(stringstream& ss) {
        string valStr;
        // Grab the next token separated by a comma
        if (!getline(ss, valStr, ',')) {
            return nullptr;
        }

        // If it's our null placeholder, return nullptr
        if (valStr == "#") {
            return nullptr;
        }

        // Create the node with the current integer value
        TreeNode* node = new TreeNode(stoi(valStr));
        
        // Rebuild the left and right subtrees sequentially
        node->left = deserializeDFS(ss);
        node->right = deserializeDFS(ss);

        return node;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        serializeDFS(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeDFS(ss);
    }
};

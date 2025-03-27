serialize-and-deserialize-binary-tree.java
  /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";  // Return an actual empty string instead of " "
        }
        
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curNode = q.front();
            q.pop();
            
            if (!curNode) {
                s += "#,";
            } else {
                s += to_string(curNode->val) + ",";
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) { // Check if the data is actually empty
            return nullptr;
        }

        stringstream s(data);
        string str;
        
        // Read the root value
        getline(s, str, ',');
        if (str == "#") return nullptr; // Handle case where the tree is empty
        
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Read left child
            if (getline(s, str, ',') && str != "#") {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            // Read right child
            if (getline(s, str, ',') && str != "#") {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        
        return root;
    }
};

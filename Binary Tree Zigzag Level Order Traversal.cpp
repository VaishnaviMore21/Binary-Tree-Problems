class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }

        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;

        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            vector<int> row(size);

            for (int i = 0; i < size; i++) {
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();  // Fix: Remove the node after processing

                // Determine the correct position to insert the node's value
                int index = leftToRight ? i : (size - 1 - i);
                row[index] = node->val;

                // Enqueue the left and right children if they exist
                if (node->left) {
                    nodesQueue.push(node->left);
                }
                if (node->right) {
                    nodesQueue.push(node->right);
                }
            }

            leftToRight = !leftToRight;  // Toggle direction
            result.push_back(row);  // Store the current level result
        }

        return result;
    }
};

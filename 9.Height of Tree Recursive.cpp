
 
class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* root) {
        // code here
           if (root == nullptr)
        return -1;

    // compute the height of left and right subtrees
    int lHeight = height(root->left);
    int rHeight = height(root->right);

    return max(lHeight, rHeight) + 1;
    }
};


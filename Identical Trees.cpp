class Solution {
  public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2) {
        // Base cases
        if (r1 == NULL && r2 == NULL) return true; // Both are NULL, so they are identical
        if (r1 == NULL || r2 == NULL) return false; // One is NULL, other is not
        
        // Check if current nodes are identical and then check subtrees
        return (r1->data == r2->data) &&
               isIdentical(r1->left, r2->left) &&
               isIdentical(r1->right, r2->right);
    }
};

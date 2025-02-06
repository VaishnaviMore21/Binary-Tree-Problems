class Solution{
    public:
    
     bool isSymmetricUtil(Node* root1, Node* root2) {
        // If both subtrees are NULL, they are symmetric
        if (root1 == NULL && root2 == NULL) return true;

        // If only one subtree is NULL, they are not symmetric
        if (root1 == NULL || root2 == NULL) return false;

        // Check if the data in the current nodes is equal
        if (root1->data != root2->data) return false;

        // Recursively check for symmetry in subtrees
        return isSymmetricUtil(root1->left, root2->right) &&
               isSymmetricUtil(root1->right, root2->left);
    }
    
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	      if (root == NULL) return true;
        
        // Call the utility function to check symmetry of subtrees
        return isSymmetricUtil(root->left, root->right);
    }
};
